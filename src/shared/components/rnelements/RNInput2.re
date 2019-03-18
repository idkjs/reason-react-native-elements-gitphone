[@genType.import "react-native-elements"]
[@genType.as "Input"]
[@bs.module "./RNInput2.gen"]
external make:
  (
    ~placeholder: option(string)=?,
    ~label: option(string)=?,
    ~containerStyle: option(BsReactNative.Style.t)=?,
    ~inputStyle: option(BsReactNative.Style.t)=?,
    ~value: option(string)=?,
    ~onChangeText: option(string => unit)=?,
    'a
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  ) =
  "";

let make = make;