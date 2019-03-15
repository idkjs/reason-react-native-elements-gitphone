// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var ReasonReact = require("reason-react/src/ReasonReact.js");
var FontAwesome = require("react-native-vector-icons/FontAwesome");

function make(name, size, color) {
  var partial_arg = {
    name: name,
    size: size,
    color: color
  };
  var partial_arg$1 = FontAwesome.default;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

exports.make = make;
/* ReasonReact Not a pure module */