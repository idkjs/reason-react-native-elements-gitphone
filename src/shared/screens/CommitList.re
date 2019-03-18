open BsReactNative;
open Utils;
module S = {
  let dimensions = Dimensions.get(`screen);
  let styles =
    StyleSheet.create(
      Style.{
      "subtitleStyle": style([
        color(String("rgba(0, 0, 0, 0.54)"))
        ]),
        "containerStyle":
          style([
            alignItems(Center),
            height(Pt(50.)),
            justifyContent(Center),
            paddingHorizontal(Pt(0.)),
            paddingTop(Pt(0.)),
            width(Pt(dimensions##width |> float_of_int)),          ]),
        "containerStyle2":
          style([
            alignItems(FlexStart),
            borderBottomWidth(1.),
            flex(1.),
            width(Pct(100.)),
          ]),
        "centerContainerStyle": style([paddingRight(Pt(20.))]),
      },
    );
};
module LeftElement = {
let styles =
    StyleSheet.create(
      Style.{
        "leftElementStyle":
          style([
            height(Pt(100.)),
             marginRight(Pt(0.))
          ]),
      },
    );
    let component = ReasonReact.statelessComponent("LeftElement");

    let make = (~item, _children) => {
      ...component,
      render: (_self) =>
    <View style=styles##leftElementStyle>
      <RNAvatar
        source={ uri: item##avatar_url }
        size="medium"
        rounded=true
      />
    </View>
    };
};

type state =
  | NotAsked
  | Loading
  | Failure
  | Success(list(CommitData.commit));

type action =
  | LoadCommits
  | LoadedCommits(list(CommitData.commit))
  | LoadCommitsFailed;

let component = ReasonReact.reducerComponent("CommitList");
let renderItem = FlatList.renderItem(({item}) =>
        <RNListItem
          title=item##author_name
          subtitle=item##message
          leftElement={<LeftElement item />}
          containerStyle=S.styles##containerStyle2
          subtitleStyle=S.styles##subtitleStyle
        />);
let make = (~navigation: Config.navigationProp,~owner, ~repo, _children) => {
  ...component,
  initialState: () => NotAsked,
  reducer: (action, _state) =>
    switch (action) {
    | LoadCommits =>
      ReasonReact.UpdateWithSideEffects(
        Loading,
        (
          self =>
            Js.Promise.(
              CommitData.fetchCommits(~owner, ~repo)
              |> then_(result =>
                   switch (result) {
                   | Some(commits) => resolve(self.send(LoadedCommits(commits)))
                   | None => resolve(self.send(LoadCommitsFailed))
                   }
                 )
              |> ignore
            )
        ),
      )
    | LoadedCommits(commits) => ReasonReact.Update(Success(commits))
    | LoadCommitsFailed => ReasonReact.Update(Failure)
    },
  didMount: self => self.send(LoadCommits),

   render: self =>
    {switch (self.state) {
      | NotAsked => ReasonReact.null
      | Loading => <ActivityIndicator color={String("#87ceeb")} />
      | Failure => <Text> {s("Something went wrong!")} </Text>
      | Success(commits) =>
        <ScrollView>
          <FlatList
            data={commits->Array.of_list}
            renderItem
            keyExtractor=((commit, _) => commit##sha)
          />
          </ScrollView>
      }
    }
};