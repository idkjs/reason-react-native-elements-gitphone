
// [@genType]
// type renderBag = {
//     name: string,
//     message: string,
// };

[@genType.import "react-native-elements"]
[@genType.as "ListItem"]
[@bs.module "./RNGHListItem.gen"]
external make:
  (
    ~name: string,
    ~message: string,
    // ~leftAvatar: ReasonReact.reactElement,
    'a
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  ) =
  "";

let make = make;