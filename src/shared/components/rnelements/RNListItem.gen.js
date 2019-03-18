/** 
 * @flow strict
 * @generated
 * @nolint
 */
/* eslint-disable */
// $FlowExpectedError: Reason checked type sufficiently
type $any = any;

// flowlint-next-line nonstrict-import:off
import {ListItem as ListItem} from 'react-native-elements';

// $FlowExpectedError: Reason checked type sufficiently
import * as React from 'react';

// $FlowExpectedError: Reason checked type sufficiently
import * as ReasonReact from 'reason-react/src/ReasonReact.js';

export type Props = {|
  +title: string, 
  +subtitle: string, 
  +leftElement: ReasonReact_reactElement, 
  +containerStyle: BsReactNative_Style_t, 
  +subtitleStyle: BsReactNative_Style_t
|};

// In case of type error, check the type of 'make' in 'RNListItem.re' and the props of 'react-native-elements'.
export function ListItemTypeChecked(props: Props) {
  return <ListItem {...props}/>;
}

// Export 'make' early to allow circular import from the '.bs.js' file.
export const make: mixed = function (title: $any, subtitle: $any, leftElement: $any, containerStyle: $any, subtitleStyle: $any, children: $any) { return ReasonReact.wrapJsForReason(ListItem, {title: title, subtitle: subtitle, leftElement: leftElement, containerStyle: containerStyle, subtitleStyle: subtitleStyle}, children); };

// flowlint-next-line nonstrict-import:off
import type {Style_t as BsReactNative_Style_t} from './BsReactNative.gen';

// flowlint-next-line nonstrict-import:off
import type {reactElement as ReasonReact_reactElement} from './ReactShim.shim';

export type source = {| +uri: string |};

export type leftAvatar = {| +source: source, +title: string |};

export type renderBag = {|
  +name: string, 
  +subtitle: string, 
  +leftAvatar: leftAvatar
|};
