open BsReactNative;
open Styles;
open Utils;
module S = {
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
            width(Pct(100.)),
          ]),
        "containerStyle2":
          style([
            alignItems(FlexStart),
            borderBottomWidth(1.),
            flex(1.),
            width(Pct(100.)),
          ]),
        "centerContainerStyle": style([paddingRight(Pt(20.))]),
        "buttonStyle":
          style([
            alignItems(Center),
            height(Pt(48.)),
            justifyContent(Center),
            paddingRight(Pt(5.)),
            width(Pt(40.)),
          ]),
          "textStyle": style([color(String("#fff"))]),
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
type commit = {
  .
  "sha": string,
  "message": string,
  "author_name": string,
  "avatar_url": string,
};

module Decode = {
  let commitDecode = json =>
  Json.Decode.{
    "sha": json |> field("sha", string),
    "message": json |> at(["commit","message"], string),
    "author_name": json |> at(["commit","author","name"], string),
    "avatar_url": json |> at(["author","avatar_url"], string),
  };
  let commits = json: list(commit) => Json.Decode.list(commitDecode, json);
};

let repoUrl = "https://api.github.com/repos/react-native-training/react-native-elements/commits";
let fetchCommits = () =>
  Js.Promise.(
    Fetch.fetch(repoUrl)
    |> then_(Fetch.Response.json)
    |> then_(json =>
         json |> Decode.commits |> (commits => Some(commits) |> resolve)
       )
    |> catch(_err => resolve(None))
  );
type state =
  | NotAsked
  | Loading
  | Failure
  | Success(list(commit));

type action =
  | LoadCommits
  | LoadedCommits(list(commit))
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
let make = (~navigation: Config.navigationProp, _children) => {
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
              fetchCommits()
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