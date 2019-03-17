open BsReactNative;

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
type optionOrError('a) =
  | Some('a)
  | None
  | Error;

type state = {weather: optionOrError(WeatherData.weather)};

type action =
  | LoadedWeather(WeatherData.weather)
  | WeatherError;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {weather: None},
  didMount: self => {
    let handleLoadedWeather = weather => self.send(LoadedWeather(weather));
    let handleWeatherError = () => self.send(WeatherError);

    WeatherData.getWeather()
    |> Js.Promise.then_(weather => {
         handleLoadedWeather(weather);
         Js.Promise.resolve();
       })
    |> Js.Promise.catch(_err => {
         handleWeatherError();
         Js.Promise.resolve();
       })
    |> ignore;
  },
  reducer: (action, _prevState) =>
    switch (action) {
    | LoadedWeather(newWeather) =>
      ReasonReact.Update({weather: Some(newWeather)})
    | WeatherError => ReasonReact.Update({weather: Error})
    },
  render: self =>
    <View style=S.styles##containerStyle>
      <Text>
        (
          switch (self.state.weather) {
          | None => ReasonReact.string("Loading weather...")
          | Error => ReasonReact.string("Error loading weather.")
          | Some({summary, temp}) =>
            <Text>
            	(ReasonReact.string(summary ++ " - " ++ string_of_float(temp)))
            </Text>
          }
        )
      </Text>
    </View>,
};