open BsReactNative;

module Styles = {
let styles = StyleSheet.create(Style.{
  "container": style([flex(1.),
    backgroundColor(String("#fff")),
    alignItems(Center),
    justifyContent(Center),
    ]),
  "title": style([
    fontWeight(`Bold),
    fontSize(Float(16.)),
    ]),
  "button":style([
    borderRadius(3.),
    padding(Pt(20.)),
    marginVertical(Pt(10.)),
    marginTop(Pt(10.)),
    backgroundColor(String("#1B95E0")),
 ]),
  "buttonText":style([
    color(String("#fff")),
    fontWeight(`Bold),
    fontSize(Float(16.)),
 ]),
});
};
let component = ReasonReact.statelessComponent("MyButton");

let make = (_children) => {
  ...component,
  render: (_self) =>  <View>
  	<ButtonEl
  	  onPress={_e => Js.log("CLICKED")}
  	  buttonStyle=Styles.styles##button
  	  underlayColor="#0A84D0"
  	  title="Rotate Logo"
  	  titleStyle=Styles.styles##buttonText
  	/>
  </View>
};