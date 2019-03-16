// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Js_json = require("bs-platform/lib/js/js_json.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");

var getCommits = fetch("https://api.github.com/repos/react-native-training/react-native-elements/commits").then((function (prim) {
              return prim.json();
            })).then((function (json) {
            return Promise.resolve(Js_json.decodeArray(json));
          })).then((function (opt) {
          return Promise.resolve(Belt_Option.getExn(opt));
        })).then((function (items) {
        return Promise.resolve(items.map((function (item) {
                          return Belt_Option.getExn(Js_json.decodeString(item));
                        })));
      }));

exports.getCommits = getCommits;
/* getCommits Not a pure module */