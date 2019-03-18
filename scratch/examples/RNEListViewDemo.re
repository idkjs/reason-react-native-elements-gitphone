open BsReactNative;
open Styles;
open Utils;
module S = {
  let styles =
    StyleSheet.create(
      Style.{
        "containerStyle":
          style([
            alignItems(Center),
            height(Pt(50.)),
            justifyContent(Center),
            paddingHorizontal(Pt(0.)),
            paddingTop(Pt(0.)),
            width(Pct(100.)),
          ]),
        "centerContainerStyle": style([paddingRight(Pt(20.))]),
        "buttonStyle":
          style([
            alignItems(Center),
            height(Pt(48.)),
            justifyContent(Center),
            paddingRight(Pt(5.)),
            width(Pt(40.)),
          ]),
          "textStyle": style([color(String("#fff"))]),
      },
    );
};

let listJst = [
  {
    "name": "Amy Farha",
    "avatar_url": "https://s3.amazonaws.com/uifaces/faces/twitter/adhamdannaway/128.jpg",
    "subtitle": "Vice President"
  },
  {
    "name": "Chris Jackson",
    "avatar_url": "https://s3.amazonaws.com/uifaces/faces/twitter/adhamdannaway/128.jpg",
    "subtitle": "Vice Chairman"
  },
];

let component = ReasonReact.statelessComponent("CommitList");

let renderItem =
FlatList.renderItem(({item}) =>
  <RNListItem
    title=item##name
    subtitle=item##subtitle
    leftAvatar={
      source:{
        uri:item##avatar_url
      },
      title:item##name
       }
  />
  );
let keyExtractor = (_item, idx) => string_of_int(idx);
let make = (~navigation: Config.navigationProp, _children) => {
  ...component,
  render: _self =>
    <ScrollView>
      <FlatList
        data={listJst->Array.of_list}
        renderItem
        keyExtractor
      />
    </ScrollView>,
};