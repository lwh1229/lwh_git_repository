
"use strict";

let EditAnnotationsData = require('./EditAnnotationsData.js')
let SetRelationship = require('./SetRelationship.js')
let DeleteAnnotations = require('./DeleteAnnotations.js')
let YAMLExport = require('./YAMLExport.js')
let GetAnnotationsData = require('./GetAnnotationsData.js')
let YAMLImport = require('./YAMLImport.js')
let ListMaps = require('./ListMaps.js')
let DeleteMap = require('./DeleteMap.js')
let PubAnnotationsData = require('./PubAnnotationsData.js')
let ResetDatabase = require('./ResetDatabase.js')
let GetAnnotations = require('./GetAnnotations.js')
let ListWorlds = require('./ListWorlds.js')
let SaveMap = require('./SaveMap.js')
let PublishMap = require('./PublishMap.js')
let SetKeyword = require('./SetKeyword.js')
let SaveAnnotationsData = require('./SaveAnnotationsData.js')
let RenameMap = require('./RenameMap.js')

module.exports = {
  EditAnnotationsData: EditAnnotationsData,
  SetRelationship: SetRelationship,
  DeleteAnnotations: DeleteAnnotations,
  YAMLExport: YAMLExport,
  GetAnnotationsData: GetAnnotationsData,
  YAMLImport: YAMLImport,
  ListMaps: ListMaps,
  DeleteMap: DeleteMap,
  PubAnnotationsData: PubAnnotationsData,
  ResetDatabase: ResetDatabase,
  GetAnnotations: GetAnnotations,
  ListWorlds: ListWorlds,
  SaveMap: SaveMap,
  PublishMap: PublishMap,
  SetKeyword: SetKeyword,
  SaveAnnotationsData: SaveAnnotationsData,
  RenameMap: RenameMap,
};
