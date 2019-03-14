import { AppRegistry } from "react-native";
import {app as App} from "./App.bs";
// import { name as appName } from "./app.json";

AppRegistry.registerComponent("App", () => App);

AppRegistry.runApplication("App", {
  rootTag: document.getElementById("root")
});
