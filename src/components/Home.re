open BsReactNative;

let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <View>
      <Input label="Owner" placeholder="Github's owner" />
      <Input label="Repo" placeholder="Github's repository name" />
      <ButtonEl title="SUBMIT">
        <Icons color="white" name="paper-plane" size=15 />
      </ButtonEl>
    </View>,
};