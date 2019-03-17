let getCommits =
  Js.Promise.(
    Fetch.fetch("https://api.github.com/repos/react-native-training/react-native-elements/commits")
    /* assume server returns `["apple", "banana", "pear", ...]` */
    |> then_(Fetch.Response.json)
    |> then_(json => Js.Json.decodeArray(json) |> resolve)
    |> then_(opt => Belt.Option.getExn(opt) |> resolve)
    |> then_(items =>
         items
         |> Js.Array.map(item => item |> Js.Json.decodeString |> Belt.Option.getExn)
         |> resolve
       )
);