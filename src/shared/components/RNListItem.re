[@genType]
type source = {
  uri:string
};
[@genType]
type leftAvatar = {
  source: source,
  title: string,
};
[@genType]
type renderBag = {
    name: string,
    subtitle: string,
    leftAvatar
};
[@genType.import "react-native-elements"]
[@genType.as "ListItem"]
[@bs.module "./RNListItem.gen"]
external make:
  (
    ~title: string,
    ~subtitle: string,
    ~leftAvatar: leftAvatar,
    'a
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  ) =
  "";

let make = make;