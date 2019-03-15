import { AppRegistry } from "react-native";
import {app as App} from "./App.bs";
// import { name as appName } from "./app.json";
import iconFont from 'react-native-vector-icons/Fonts/FontAwesome.ttf';

const iconFontStyles = `@font-face {
  src: url(${iconFont});
  font-family: FontAwesome;
}`;

// Create stylesheet
const style = document.createElement('style');
style.type = 'text/css';
if (style.styleSheet) {
  style.styleSheet.cssText = iconFontStyles;
} else {
  style.appendChild(document.createTextNode(iconFontStyles));
}
// Inject stylesheet
document.head.appendChild(style);

AppRegistry.registerComponent("App", () => App);

AppRegistry.runApplication("App", {
  rootTag: document.getElementById("root")
});
