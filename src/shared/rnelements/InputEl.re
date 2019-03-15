[@bs.module "react-native-elements"]
  external className : ReasonReact.reactClass = "Input";
  let make = (~placeholder: option(string)=?,
  ~label: option(string)=?,
  ~containerStyle: option(BsReactNative.Style.t)=?,
  ~inputStyle: option(BsReactNative.Style.t)=?,
   children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=className,
      ~props=Js.Nullable.({
        "placeholder": fromOption(placeholder),
        "label": fromOption(label),
        "containerStyle": fromOption(containerStyle),
        "inputStyle": fromOption(inputStyle),
      }),
      children,
);