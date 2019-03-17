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

export type Props = {| +name: string, +message: string |};

// In case of type error, check the type of 'make' in 'RNGHListItem.re' and the props of 'react-native-elements'.
export function ListItemTypeChecked(props: Props) {
  return <ListItem {...props}/>;
}

// Export 'make' early to allow circular import from the '.bs.js' file.
export const make: mixed = function (name: $any, message: $any, children: $any) { return ReasonReact.wrapJsForReason(ListItem, {name: name, message: message}, children); };
