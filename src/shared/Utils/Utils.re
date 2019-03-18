let s = ReasonReact.string;

type debounceOptions = {
  .
  "leading": bool,
  "maxWait": int,
  "trailing": bool
};

module Debounce = {
  [@bs.module]
  external _make :
    ('fArgs => 'fOutput, int, debounceOptions) => [@bs] ('fArgs => 'fOutput) =
    "lodash.debounce";
  let make = (~wait=0, ~options=Js.Obj.empty(), f) => _make(f, wait, options);
  let call = (input, f) => [@bs] f(input);
};
let initialsRe = [%bs.re "/^[A-Za-z]/g"];
  let resolveOption = opt =>
    switch (opt) {
    | None => ""
    | Some(s) => s
};
let resolveRegex = (str) => {
    initialsRe
    |> Js.Re.exec(str)
      |> (
        result =>
          switch result {
          | Some(result) => Js.Re.captures(result)[0] |> Js.Nullable.toOption
          | None => None
          }
      )
      |> Js.Option.getWithDefault("");
};

let initials(arr) = Array.length(arr) < 1 ? arr[0] ++ arr[0] : arr[0] ++ arr[Array.length(arr) - 1];
let getInitials = (string) =>
string
|> Js.String.split(" ")
|>Js.Array.map(resolveRegex)
|> Array.map(String.uppercase)
|> initials
