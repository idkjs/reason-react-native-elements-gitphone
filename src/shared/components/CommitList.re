open BsReactNative;
open Styles;
open Utils;
let component = ReasonReact.statelessComponent("CommitList");

let make =(~navigation: Config.navigationProp, _children )=> {
  ...component,
  render: _self =>
    <View style=styles##container>
      <Text> "Placeholder for second screen"->s </Text>
    </View>,
};