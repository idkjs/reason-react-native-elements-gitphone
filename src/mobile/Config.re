open BsReactNavigation;

type route =
    | Home
    | FetchRepos
    | CommitList;

type navigationProp = StackNavigator.navigation(route);
