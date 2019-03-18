/** 
 * @flow strict
 * @generated
 * @nolint
 */
/* eslint-disable */
// $FlowExpectedError: Reason checked type sufficiently
type $any = any;

// flowlint-next-line nonstrict-import:off
import {Input as Input} from 'react-native-elements';

// $FlowExpectedError: Reason checked type sufficiently
import * as React from 'react';

// $FlowExpectedError: Reason checked type sufficiently
import * as ReasonReact from 'reason-react/src/ReasonReact.js';

export type Props = {|
  +placeholder?: string, 
  +label?: string, 
  +containerStyle?: BsReactNative_Style_t, 
  +inputStyle?: BsReactNative_Style_t, 
  +value?: string, 
  +onChangeText?: (string) => void
|};

// In case of type error, check the type of 'make' in 'RNInput2.re' and the props of 'react-native-elements'.
export function InputTypeChecked(props: Props) {
  return <Input {...props}/>;
}

// Export 'make' early to allow circular import from the '.bs.js' file.
export const make: mixed = function (placeholder: $any, label: $any, containerStyle: $any, inputStyle: $any, value: $any, onChangeText: $any, children: $any) { return ReasonReact.wrapJsForReason(Input, {placeholder: placeholder, label: label, containerStyle: containerStyle, inputStyle: inputStyle, value: value, onChangeText: onChangeText}, children); };

// flowlint-next-line nonstrict-import:off
import type {Style_t as BsReactNative_Style_t} from './BsReactNative.gen';
