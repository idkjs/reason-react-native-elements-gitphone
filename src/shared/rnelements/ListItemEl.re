[@bs.module "react-native-elements"]
external className: ReasonReact.reactClass = "ListItem";

type source = {
  uri:string
};

type leftAvatar = {
  rounded: Js.Nullable.t(bool),
  source: Js.Nullable.t(source),
  title: Js.Nullable.t(string),
};

[@bs.obj]
external makeProps:
  (
  ~leftAvatar:Js.Nullable.t(leftAvatar)=?,
  ~title:Js.Nullable.t(string)=?,
  ~subtitle:Js.Nullable.t(string)=?,
  unit) =>
  _ =
  "";
let make = (~leftAvatar=?, ~title=?,~subtitle=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=className,
    ~props=
      makeProps(
        ~leftAvatar=Js.Nullable.fromOption(leftAvatar),
        ~title=Js.Nullable.fromOption(title),
        ~subtitle=Js.Nullable.fromOption(subtitle),
        (),
      ),
    children,
  );