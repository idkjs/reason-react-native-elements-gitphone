/**
 * @format
 */

import {AppRegistry} from 'react-native';
// import {app as App} from './src/App.bs.js';
// import App from './src/App.bs.js';
import App from './App';

import {name as appName} from './app.json';

AppRegistry.registerComponent(appName, () => App);
