open BsReactNavigation;

type route =
    | Home
    | CommitList;

type navigationProp = StackNavigator.navigation(route);
