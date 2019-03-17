
type commit = {
  message: string,
  author_name: string,
  avatar_url: string,
};
type commits = list(commit);

let decodeCommit = (json: Js.Json.t): commit =>
  Json.Decode.{
    message: json |> at(["commit","message"], string),
    author_name: json |> at(["commit","author","name"], string),
    avatar_url: json |> at(["author","avatar_url"], string),
  };

let reposUrl = "https://api.github.com/repos/react-native-training/react-native-elements/commits";

let decodeCommits = json : commits =>
json |> Json.Decode.list(decodeCommit);

let fetchCommits = () =>
  Js.Promise.(
    Fetch.fetch(reposUrl)
      |> then_(ApiUtils.responseJsonOrError)
      |> then_(
        json =>{
          Js.log(json);
          let commits = decodeCommits(json);
          Belt.List.forEach(commits, c => Js.log(c))
          Js.log(commits);
          resolve(commits)
        }
      )
  );