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

let repoUrl = (~owner,~repo) => "https://api.github.com/repos/" ++ owner ++ "/" ++ repo ++ "/commits";
let fetchCommits = (~owner,~repo) =>
  Js.Promise.(
    Fetch.fetch(repoUrl(~owner,~repo))
    |> then_(Fetch.Response.json)
    |> then_(json =>
         json |> Decode.commits |> (commits => Some(commits) |> resolve)
       )
    |> catch(_err => resolve(None))
  );