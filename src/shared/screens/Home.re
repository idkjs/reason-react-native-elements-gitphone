open BsReactNative;
open Styles;
type state = {
  owner: string,
  repo: string
};
type action = | UpdateOwner(string) | UpdateRepo(string);

let component = ReasonReact.reducerComponent("Home");
//  let renderPlaneIcon = <RNIcons.FontAwesome size=15. name=`_paperPlane color= "white" />;
 let renderPlaneIcon = <Icons name="paper-plane" size=15 color="white"/>
 let changeRepoValue = send => {
  open Utils.Debounce;
  let update = make(newValue => send(UpdateRepo(newValue)), ~wait=250);
  newValue => update |> call(newValue);
};
 let changeOwnerValue = send => {
  open Utils.Debounce;
  let update = make(newValue => send(UpdateOwner(newValue)), ~wait=250);
  newValue => update |> call(newValue);
};
let make = (~navigation: Config.navigationProp,_children) => {
  ...component,
  initialState: () => {owner:"",repo:""},
  reducer: (action, state) =>
  switch action {
    | UpdateOwner(text) => ReasonReact.Update({...state, owner:text })
    | UpdateRepo(text) => ReasonReact.Update({...state, repo:text })
},
  render: ({state,send}) =>
    <View style=styles##container>
      <Input containerStyle=InputS.containerStyle inputStyle=InputS.inputStyle label="Owner" placeholder="Github's owner" onChange=(changeOwnerValue(send)) />
      <Input containerStyle=InputS.containerStyle inputStyle=InputS.inputStyle label="Repo" placeholder="Github's repository name" onChange=(changeRepoValue(send)) />
      <RNElements.Button buttonStyle=ButtonS.containerStyle icon=renderPlaneIcon title="SUBMIT" onPress={ _evt => navigation.push(CommitList(state.owner, state.repo))} />
    </View>
};