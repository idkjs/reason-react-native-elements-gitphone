open BsReactNative;
module InputS = {
  open Style;
  let containerStyle = style([marginBottom(Pt(10.))]);
  let inputStyle = style([height(Pt(46.))]);
};
module ButtonS = {
  open Style;

  let containerStyle = style([paddingHorizontal(Pt(10.))]);
};
let styles =
  StyleSheet.create(
    Style.{
      "container":
        style([
          display(Flex),
          flex(1.),
          alignItems(Center),
          backgroundColor(String("#fff")),
          height(Pct(100.)),
          justifyContent(Center),
        ]),
    },
  );