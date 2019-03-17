open BsReactNative;
open Styles;

type commit = {
  message: string,
  author_name: string,
  avatar_url: string,
};

type state =
  | NotAsked
  | Loading
  | Failure
  | Success(list(commit));

module Decode = {
  let commitDecode = (json: Js.Json.t): commit =>
  Json.Decode.{
    message: json |> at(["commit","message"], string),
    author_name: json |> at(["commit","author","name"], string),
    avatar_url: json |> at(["author","avatar_url"], string),
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

type action =
  | LoadCommits
  | LoadedCommits(list(commit))
  | LoadCommitsFailed;

let component = ReasonReact.reducerComponent("FetchComponent");

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
    let onPressButton = () => navigation.push(CommitList);
    <View style=styles##container>
      <RNElements.Button buttonStyle=ButtonS.containerStyle  title="FetchCommits" onPress={ _evt => onPressButton()} />
    </View>}
    | Loading => <Text> {str("Loading...")} </Text>
    | Failure => <Text> {str("Something went wrong!")} </Text>
    | Success(commits) =>
    <View style=styles##container>
      <RNElements.Button buttonStyle=ButtonS.containerStyle  title="Load Commits" onPress={ _evt => self.send(LoadCommits)} />
      <ScrollView>
    <Weather />

    </ScrollView>
    </View>
    },
};