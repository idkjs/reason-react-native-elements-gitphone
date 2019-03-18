open BsReactNavigation;

type route =
    | Home
    | CommitList(string, string);

type navigationProp = StackNavigator.navigation(route);
