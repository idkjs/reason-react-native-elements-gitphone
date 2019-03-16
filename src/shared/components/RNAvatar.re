[@genType.import "react-native-elements"]
[@genType.as "Avatar"]
[@bs.module "./RNAvatar.gen"]
external make:
  (
    ~source: string,
    ~size: string,
    ~rounded: bool,
    'a
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  ) =
  "";

let make = make;