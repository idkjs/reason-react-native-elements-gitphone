open BsReactNative;
open Styles;
let component = ReasonReact.statelessComponent("Home");
 let renderPlaneIcon = <RNIcons.FontAwesome size=15. name=`_paperPlane color= "white" />;
 let renderPlaneIcon2 = <Icons name="paper-plane" size=15 color="white"/>
let make = _children => {
  ...component,
  render: _self =>
    <View style=styles##container>
      <RNElements.Input containerStyle=InputS.containerStyle inputStyle=InputS.inputStyle label="Owner" placeholder="Github's owner" />
      <RNElements.Input containerStyle=InputS.containerStyle inputStyle=InputS.inputStyle label="Repo" placeholder="Github's repository name" />
      <RNElements.Button buttonStyle=ButtonS.containerStyle icon=renderPlaneIcon2 title="SUBMIT" />
    </View>,
};