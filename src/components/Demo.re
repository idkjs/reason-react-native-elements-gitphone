open BsReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "container": style([flex(1.), backgroundColor(String("#374046"))]),
      "navBar":
        style([
          flexDirection(Row),
          paddingTop(Pt(30.)),
          height(Pt(64.)),
          backgroundColor(String("#1EAAF1")),
        ]),
        "navBarButton": style([color(String("#FFFFFF")),textAlign(Center),width(Pt(64.))]),
        "navBarHeader": style([flex(1.),color(String("#FFFFFF")),fontWeight(`Bold),textAlign(Center)]),
        "content": style([flex(1.),justifyContent(Center),alignItems(Center),backgroundColor(String("#374046"))]),
        "text": style([color(String("#EEEEEE"))]),
    },
  );

let component = ReasonReact.statelessComponent("Demo");

let make = _children => {
  ...component,
  render: _self =>
    <View style=styles##container>
      <View style=styles##navBar>
        <Text style=styles##navBarButton> (ReasonReact.string("Back")) </Text>
        <Text style=styles##navBarHeader> (ReasonReact.string ("Awesome App")) </Text>
        <Text style=styles##navBarButton> (ReasonReact.string ("More")) </Text>
      </View>
      <View style=styles##content>
        <Text style=styles##text>
          (ReasonReact.string
          ("Welcome to Awesome App!"))
        </Text>
      </View>
    </View>,
};