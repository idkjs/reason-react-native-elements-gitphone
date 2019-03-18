
type state = {value: string};

type action =
  | ChangeValue(string);

let component = ReasonReact.reducerComponent("Input2");
let reducer = (action, _state) =>
  switch (action) {
  | ChangeValue(newValue) => ReasonReact.Update({value: newValue})
  };

let make = (~containerStyle, ~inputStyle,
~initialValue="", ~label, ~placeholder, ~onChange=_newValue => (), _children) => {
  ...component,
  initialState: () => {value: initialValue},
  reducer,
  render: ({send, state:{value}}) =>
  <RNElements.Input
    containerStyle
    inputStyle
    label
    placeholder
    value=value
    onChangeText={
      value =>{
        send(ChangeValue(value));
        onChange(value)
      }
    }
    />
};