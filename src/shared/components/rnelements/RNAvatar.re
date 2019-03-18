
[@genType]
type source = {
  uri:string
};
[@genType.import "react-native-elements"]
[@genType.as "Avatar"]
[@bs.module "./RNAvatar.gen"]
external make:
  (
    ~source: source,
    ~size: string,
    ~title: string,
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