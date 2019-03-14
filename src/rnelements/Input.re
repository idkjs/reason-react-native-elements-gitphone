[@bs.module "react-native-elements"]
  external className : ReasonReact.reactClass = "Input";
  let make = (~placeholder: option(string)=?,~label: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=className,
      ~props=Js.Nullable.({
        "placeholder": fromOption(placeholder),
        "label": fromOption(label),
      }),
      children,
);