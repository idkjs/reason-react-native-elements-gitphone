[@bs.module "react-native-elements"]
external className: ReasonReact.reactClass = "Avatar";
[@bs.obj]
external makeProps:
  (~size: Js.Nullable.t(string)=?, ~rounded: Js.Nullable.t(bool)=?, unit) =>
  _ =
  "";
let make = (~size=?, ~rounded=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=className,
    ~props=
      makeProps(
        ~size=Js.Nullable.fromOption(size),
        ~rounded=Js.Nullable.fromOption(rounded),
        (),
      ),
    children,
  );