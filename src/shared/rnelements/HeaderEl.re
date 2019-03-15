[@bs.module "react-native-elements"]
external className: ReasonReact.reactClass = "Header";
let make =
    (
      ~title: option(string)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=className,
    ~props=
      Js.Nullable.{
        "title": fromOption(title),
      },
    children,
  );