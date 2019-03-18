open BsReactNative;
open Styles;
module S = {
  let styles =
    StyleSheet.create(
      Style.{
        "container": style([width(Pct(100.)), padding(Pt(20.))]),
        "currencyWrapper":
          style([
            padding(Pt(20.)),
            flexDirection(Row),
            justifyContent(SpaceBetween),
            alignItems(Center),
            borderBottomWidth(1.),
            borderBottomColor(String(Colors.teal)),
          ]),
        "currencyWrapperWithoutBorder":
          style([
            padding(Pt(20.)),
            flexDirection(Row),
            justifyContent(SpaceBetween),
            alignItems(FlexStart),
          ]),
        "currency":
          style([
            fontSize(Float(64.)),
            fontWeight(`_100),
            color(String(Colors.grey)),
            letterSpacing(4.),
          ]),
      },
    );
};

type commit = {
  .
  "message": string,
  "author_name": string,
  "avatar_url": string,
};

module Decode = {
  let commitDecode = json =>
  Json.Decode.{
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

let component = ReasonReact.reducerComponent("FetchComponent");

// let renderItem =
// FlatList.renderItem(({item}) =>
//   <RNGHListItem
//     name=item##author_name
//     message=item##message
//   />
//   );
let keyExtractor = (_item, idx) => string_of_int(idx);
let str = ReasonReact.string;
let make = (~navigation: Config.navigationProp,_children) => {
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
  render: self =>
    switch (self.state) {
    | NotAsked =>
      {
    <View style=styles##container>
      <RNElements.Button buttonStyle=ButtonS.containerStyle  title="FetchCommits" onPress={ _evt => self.send(LoadCommits)} />
    </View>}
    | Loading => <Text> {str("Loading...")} </Text>
    | Failure => <Text> {str("Something went wrong!")} </Text>
    | Success(commits) => {
      let commits = commits->Array.of_list;
      let renderItem = (idx, commit:commit) => {
              let name = commit##author_name;
              let message = commit##message;
              Js.log2(name,idx);
              <View key=name>
                <Text style=S.styles##currency> name->str </Text>
                <Text style=S.styles##currency> message->str </Text>
        </View>;
      };
      // <ScrollView>
      <View style=S.styles##container>
                {
                  commits ->Belt.Array.mapWithIndex(_,renderItem)->ReasonReact.array
                }
    </View>;
    };

        // <FlatList
        //   data={commits->Array.of_list}
        //   renderItem
        //   keyExtractor
        // />
      // </ScrollView>
    },
};