// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var ReasonReact = require("reason-react/src/ReasonReact.js");
var Js_null_undefined = require("bs-platform/lib/js/js_null_undefined.js");
var ReactNativeElements = require("react-native-elements");

function make(size, rounded, children) {
  return ReasonReact.wrapJsForReason(ReactNativeElements.Avatar, {
              size: Js_null_undefined.fromOption(size),
              rounded: Js_null_undefined.fromOption(rounded)
            }, children);
}

exports.make = make;
/* ReasonReact Not a pure module */
