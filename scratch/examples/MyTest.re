open BsReactNative;
let component = ReasonReact.statelessComponent("MyTest");

let make = (_children) => {
  ...component,
  render: (_self) =>  <View>
    <Text> (ReasonReact.string("Let's get this party started!")) </Text>
  </View>
};