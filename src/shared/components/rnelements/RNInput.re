[@bs.module "react-native-elements"]
  external className : ReasonReact.reactClass = "Input";
  let make = (~placeholder: option(string)=?,
  ~label: option(string)=?,
  ~containerStyle: option(BsReactNative.Style.t)=?,
  ~inputStyle: option(BsReactNative.Style.t)=?,
  ~value: option(string)=?,
  ~onChangeText: option(string => unit)=?,

   children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=className,
      ~props=Js.Nullable.({
        "placeholder": fromOption(placeholder),
        "onChangeText": fromOption(onChangeText),
        "label": fromOption(label),
        "containerStyle": fromOption(containerStyle),
        "inputStyle": fromOption(inputStyle),
        "value": fromOption(value),
      }),
      children,
);