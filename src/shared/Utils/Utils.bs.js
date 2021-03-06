// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var $$String = require("bs-platform/lib/js/string.js");
var Js_option = require("bs-platform/lib/js/js_option.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var LodashDebounce = require("lodash.debounce");

function s(prim) {
  return prim;
}

function make($staropt$star, $staropt$star$1, f) {
  var wait = $staropt$star !== undefined ? $staropt$star : 0;
  var options = $staropt$star$1 !== undefined ? Caml_option.valFromOption($staropt$star$1) : { };
  return LodashDebounce(f, wait, options);
}

function call(input, f) {
  return f(input);
}

var Debounce = /* module */[
  /* make */make,
  /* call */call
];

var initialsRe = (/^[A-Za-z]/g);

function resolveOption(opt) {
  if (opt !== undefined) {
    return opt;
  } else {
    return "";
  }
}

function resolveRegex(str) {
  var result = initialsRe.exec(str);
  return Js_option.getWithDefault("", result !== null ? Caml_option.nullable_to_opt(Caml_array.caml_array_get(result, 0)) : undefined);
}

function initials(arr) {
  var match = arr.length < 1;
  if (match) {
    return Caml_array.caml_array_get(arr, 0) + Caml_array.caml_array_get(arr, 0);
  } else {
    return Caml_array.caml_array_get(arr, 0) + Caml_array.caml_array_get(arr, arr.length - 1 | 0);
  }
}

function getInitials(string) {
  return initials($$Array.map($$String.uppercase, string.split(" ").map(resolveRegex)));
}

exports.s = s;
exports.Debounce = Debounce;
exports.initialsRe = initialsRe;
exports.resolveOption = resolveOption;
exports.resolveRegex = resolveRegex;
exports.initials = initials;
exports.getInitials = getInitials;
/* initialsRe Not a pure module */
