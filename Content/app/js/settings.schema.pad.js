var MOKI_SCHEMA = 



{ "$schema" : "http://json-schema.org/draft-04/schema",
  "type" : "object",
 
  "required" :
     [ "Version", "Groups" ],
 
  "properties" : {
      "Version" : { "type" : "integer", "minimum" : 1 },
      "Groups" : { "type" : "array", "minItems" : 1, "items" :
         { "type" : "object", "required" : [ "Title", "Settings" ], "properties" : {
           "Title" : { "type" : "string" },
           "Settings" : { "type" : "array", "items" : { "$ref" : "#/definitions/AnySetting" } } } } }
  },
 
 
 
  "definitions" : {
      
      
      
      
      "AnySetting" : { "oneOf" : [
          { "$ref" : "#/definitions/Header" },
          { "$ref" : "#/definitions/TextField" },
          { "$ref" : "#/definitions/ToggleSwitch" },
          { "$ref" : "#/definitions/List" },
          { "$ref" : "#/definitions/ComboBox" },
          { "$ref" : "#/definitions/Pane" },
          { "$ref" : "#/definitions/TabPane" },
          { "$ref" : "#/definitions/Slider" },
          { "$ref" : "#/definitions/Collection" } ]
      },
      
      
      
      
      
            
      "Header" : {
          "required" :
             [ "Type", "Title" ],
          "properties" : {
             "Type" : { "pattern" : "^Header$" },
             "Title" : { "type" : "string" },
             "SubTitle" : { "type" : "string" } }
      },
      
      

      
      
      "List" : {
          "required" :
             [ "Type", "Key", "ItemTemplate" ],
          "properties" : {
              "Type" : { "pattern" : "^List$" },
              "Key" : { "type" : "string" },
              "ItemTemplate" : { "type" : "array", "items" : { "$ref" : "#/definitions/AnySetting" } },
              "Title" : { "type" : "string" },
              "SubTitle" : { "type" : "string" },
              "Class" : { "type" : "array", "items" : { "type" : "string", "description" :
                 "Classes used by MokiManage include: HideInApp, HideInWeb, HideInBoth" } } }
      },
      
      
      
      
      "Pane" : {
          "required" :
             [ "Type", "Settings" ],
          "properties" : {
             "Type" : { "pattern" : "^Pane$" },
             "Settings" : { "type" : "array", "items" : { "$ref" : "#/definitions/AnySetting" } },
             "Title" : { "type" : "string" },
             "SubTitle" : { "type" : "string" },
             "Class" : { "type" : "array", "items": {"type" : "string", "description" :
                "Classes used by MokiManage include: HideInApp, HideInWeb, HideInBoth" } } }
      },
      
      
      
      "TabPane" : {
          "required" :
             [ "Type", "Key", "Tabs", "SelectedTab" ],
          "properties" : {
              "Type" : { "pattern" : "^TabPane$" },
              "Key" : { "type" : "string" },
              "Tabs" : { "type" : "array", "items" : { "type" : "object",
                 "required" :
                    [ "Title", "Settings" ],
                 "properties" : {
                     "Title" : { "type" : "string" },
                     "Settings" : { "type" : "array", "items" : { "$ref" : "#/definitions/AnySetting" } } } } },
              "SelectedTab" : { "type" : "integer", "minimum" : 0},
              "Class" : { "type" : "array", "items": {"type" : "string", "description" :
                 "Classes used by MokiManage include: HideInApp, HideInWeb, HideInBoth"} } }
        },
      
      
      
      
      
      
      
      
      
      "ComboBox" : {
          "required" :
             [ "Type", "Key", "Value", "Options" ],
          "properties" : {
             "Type" : { "pattern" : "^ComboBox$" },
             "Key" : { "type" : "string" },
             "Value" : { "type" : "string" },
             "Options" : { "type" : "array", "items" : { "type" : "object",
                "required" :
                   [ "Value" ],
                "properties" : {
                   "Value" : { "type" : "string" },
                   "Title" : { "type" : "string" } } } },
             "Class" : { "type" : "array", "items" : { "type" : "string", "description" :
                "Classes used by MokiManage include: Single, Multiple, HideInApp, HideInWeb, HideInBoth" } } }
      },
      

      
      "Slider" : {
          "required" :
             [ "Type", "Key", "Value", "MaxValue" ],
          "properties" : {
              "Type" : { "pattern" : "^Slider$" },
              "Key" : { "type" : "string" },
              "Value" : { "type" : "number" },
              "MaxValue" : { "type" : "number" },
              "MinValue" : { "type" : "number", "default" : 0 },
              "Step" : { "type" : "number", "default" : 1, "exclusiveMinimum" : true, "minimum" : 0 } }
      },

      
      
      "TextField" : {
          "required" :
             [ "Type", "Key", "Value" ],
          "properties" : {
              "Type" : { "pattern" : "^TextField$" },
              "Key" : { "type" : "string" },
              "Value" : { "type" : "string" },
              "Title" : { "type" : "string" },
              "SubTitle" : { "type" : "string" },
              "Tooltip" : { "type" : "string" },
              "Placeholder" : { "type" : "string" },
              "ValidationErrorMsg" : { "type" : "string" },
              "ValidationRegex" : { "type" : "string" },
              "Class" : {  "type" : "array", "items" : { "type" : "string", "description" :
                 "Classes used by MokiManage include: Password, Color, Content, Int, Float, HideInApp, HideInWeb, HideInBoth" } } }
      },
      
      
      
      "ToggleSwitch" : {
          "required" :
             [ "Type", "Key", "Value" ],
          "properties" : {
              "Type" : { "pattern" : "^ToggleSwitch$" },
              "Key" : { "type" : "string" },
              "Value" : { "type" : "boolean" },
              "Title" : { "type" : "string" },
              "SubTitle" : { "type" : "string" },
              "Class" : { "type" : "array", "items" : { "type" : "string", "description" :
                 "Classes used by MokiManage include: HideInApp, HideInWeb, HideInBoth" } } }
      },
      
      
      
      "Collection" : {
          "required" :
             [ "Type", "Settings" ],
          "properties" : {
             "Type" : { "pattern" : "^Collection$" },
             "Settings" : { "type" : "array", "items" : { "$ref" : "#/definitions/AnySetting" } },
             "Disable" : { "required" : [ "If" ], "properties" : {
                "If" : { "$ref" : "#/definitions/IfCondition" } } },
             "Hide" : { "required" : [ "If" ], "properties" : {
                "If" : { "$ref" : "#/definitions/IfCondition" } }},
             "SetValue" : { "required" : [ "If", "Value" ], "properties" : {
                "If" : { "$ref" : "#/definitions/IfCondition" },
                "Value" : { "type" : [ "string", "number", "boolean" ] } } } }
      },
      
      "IfCondition" : { "type" : "array", "items" :
         { "type" : "object", "required" : [ "Key", "Operator", "Value" ], "properties" : {
           "Key" : { "type" : "string" },
           "Operator" : { "type" : "string", "enum" :
              [ "==", "!=", ">", ">=", "<", "<=" ] },
           "Value" : { "type" : [ "string", "number", "boolean" ] } } }
      }
      
      
      
    }
};