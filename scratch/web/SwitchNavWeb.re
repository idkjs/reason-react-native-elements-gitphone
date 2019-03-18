// open BsReactNavigationWeb;

open Routes;

module Stack =
  SwitchNavigatorWeb.Create({
    open SwitchNavigatorWeb;

    type route = Routes.route;

    let initialRoute = Home;

    let getScreen = (route, navigation) =>
      switch (route) {
      | Home => (<Home navigation />, screenOptions(~title="Home", ()))
      | CommitList => (<CommitList navigation />, screenOptions(~title="CommitList", ()))
      };
  });


let app = Stack.render;
