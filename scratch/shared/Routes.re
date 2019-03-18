open BsRandomNav;

type route =
    | Home
    | CommitList;

type navigation = SwitchNavigatorWeb.navigation(route);
