open BsReactNavigation;

/**
  * Route and Navigation types are kept in a separate module to
  * handle circular references between modules
  */
open Config;

module Stack =
  StackNavigator.Create({
    open StackNavigator;

    /**
      * StackNavigator requires `route` type to be defined.
      */
    type route = Config.route;

    /**
      * Initial route to start with. Has to be one of `route` variants.
      */
    let initialRoute = Home;

    /**
      * Returns a screen for a given route and its options.
      *
      * To declare options, you call `StackNavigator.screenOptions` and provide
      * same keys as `navigationOptions` of React Navigation.
      *
      * This is to allow optional fields to be provided.
      */
      let getPlace = id => Data.places->Belt.List.getBy(place => place._id == id);
    let getScreen = (route, navigation) =>
      switch (route) {
      | Home => (<Places navigation />, screenOptions(~title="Home", ()))
      | Place(id) =>{
          Js.log(id);
          switch (getPlace(id)) {
          | None => (<NotFound navigation />, screenOptions(~title="NotFound", ()))
          | Some(place) => (<Place place navigation />, screenOptions(~title="Place", ()))
          }}
      | NotFound => (<NotFound navigation />, screenOptions(~title="NotFound", ()))
      };
  });

let render = Stack.render;