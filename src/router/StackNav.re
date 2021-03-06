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
    let getScreen = (route, navigation) =>
      switch (route) {
      | Home => (<Home navigation />, screenOptions(~title="Home", ()))
      | CommitList(owner, repo) => (<CommitList owner repo navigation />, screenOptions(~title="CommitList", ()))
      };
  });

let render = Stack.render;