type p;
[@bs.module "react-native-elements"]
external className: ReasonReact.reactClass = "Button";
let make =
    (
      ~buttonStyle: option(BsReactNative.Style.t)=?,
      ~underlayColor: option(string)=?,
      ~clear: option(bool)=?,
      ~containerStyle: option(BsReactNative.Style.t)=?,
      ~disabled: option(bool)=?,
      ~disabledStyle: option(BsReactNative.Style.t)=?,
      ~disabledTitleStyle: option(BsReactNative.Style.t)=?,
      ~icon: option(ReasonReact.reactElement)=?,
      ~iconContainerStyle: option(BsReactNative.Style.t)=?,
      ~iconRight: option(bool)=?,
      ~loading: option(bool)=?,
      ~loadingProps: option(BsReactNative.Style.t)=?,
      ~loadingStyle: option(BsReactNative.Style.t)=?,
      ~onPress: option(p => unit)=?,
      ~title: option(string)=?,
      ~titleProps: option(BsReactNative.Style.t)=?,
      ~titleStyle: option(BsReactNative.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=className,
    ~props=
      Js.Nullable.{
        "buttonStyle": fromOption(buttonStyle),
        "underlayColor": fromOption(underlayColor),
        "clear": fromOption(clear),
        "containerStyle": fromOption(containerStyle),
        "disabled": fromOption(disabled),
        "disabledStyle": fromOption(disabledStyle),
        "disabledTitleStyle": fromOption(disabledTitleStyle),
        "icon": fromOption(icon),
        "iconContainerStyle": fromOption(iconContainerStyle),
        "iconRight": fromOption(iconRight),
        "loading": fromOption(loading),
        "loadingProps": fromOption(loadingProps),
        "loadingStyle": fromOption(loadingStyle),
        "onPress": fromOption(onPress),
        "title": fromOption(title),
        "titleProps": fromOption(titleProps),
        "titleStyle": fromOption(titleStyle),
      },
    children,
  );