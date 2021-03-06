<?php

/**
 * @file
 * ulf_skive_search_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_skive_search_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function ulf_skive_search_settings_default_search_api_index() {
  $items = array();
  $items['courses'] = entity_import('search_api_index', '{
    "name" : "Courses",
    "machine_name" : "courses",
    "description" : null,
    "server" : "search_node",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "course" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "search_node_indexes" : "c726cdaf9f1e3f064f7b362ab9695733",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "author:field_profile_name" : { "type" : "text" },
        "author:url" : { "type" : "uri" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_activities:value" : { "type" : "text" },
        "field_background_knowledge:value" : { "type" : "text" },
        "field_educational_goals" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_free" : { "type" : "boolean" },
        "field_full_description:value" : { "type" : "text" },
        "field_image:file" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "file" },
        "field_location" : { "type" : "string" },
        "field_offer_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_period:value" : { "type" : "date" },
        "field_period:value2" : { "type" : "date" },
        "field_period_full_year" : { "type" : "boolean" },
        "field_post_work:value" : { "type" : "text" },
        "field_price" : { "type" : "decimal" },
        "field_subject" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_subject:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_subjects_primary_school" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_subjects_youth" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target_group" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_target_group_sub" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "exclude" : {
          "status" : 0,
          "weight" : "-50",
          "settings" : { "fields" : { "name" : "", "values" : "" } }
        },
        "location" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "field_name" : "field_location" }
        },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "author:field_profile_name" : true,
              "field_full_description:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "author:field_profile_name" : true,
              "field_full_description:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "title" : true,
              "author:field_profile_name" : true,
              "field_full_description:value" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "author:field_profile_name" : true,
              "field_full_description:value" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "author:field_profile_name" : true,
              "field_full_description:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['educators'] = entity_import('search_api_index', '{
    "name" : "Educators",
    "machine_name" : "educators",
    "description" : null,
    "server" : "search_node",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "course_educators" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "search_node_indexes" : "a2caac2b8da20992fa399d3c8f3e5d44",
      "fields" : {
        "author:field_profile_name" : { "type" : "text" },
        "author:uid" : { "type" : "integer" },
        "author:url" : { "type" : "uri" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_educational_goals" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_free" : { "type" : "boolean" },
        "field_image:file" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "file" },
        "field_location" : { "type" : "string" },
        "field_offer_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_period:value" : { "type" : "date" },
        "field_period:value2" : { "type" : "date" },
        "field_price" : { "type" : "decimal" },
        "field_relevance_educators" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_relevance_educators:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_relevance_primary_school" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_relevance_primary_school:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_relevance_upper_school" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_relevance_upper_school:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_subject" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_subject:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_subjects_primary_school" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_subjects_youth" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target_group" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_target_group_sub" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_teaser" : { "type" : "text" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "8.0" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "exclude" : {
          "status" : 0,
          "weight" : "-50",
          "settings" : { "fields" : { "name" : "", "values" : "" } }
        },
        "location" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "field_name" : "field_location" }
        },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "field_teaser" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "field_teaser" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true, "field_teaser" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "field_teaser" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_teaser" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['users'] = entity_import('search_api_index', '{
    "name" : "Users",
    "machine_name" : "users",
    "description" : null,
    "server" : "search_node",
    "item_type" : "user",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "search_node_indexes" : "e02cb40668a47329108ceffeb574de1b",
      "fields" : {
        "created" : { "type" : "date" },
        "field_image:file" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "file" },
        "field_location" : { "type" : "string" },
        "field_profile_contact" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_profile_description:value" : { "type" : "text" },
        "field_profile_mail" : { "type" : "text" },
        "field_profile_name" : { "type" : "text" },
        "field_profile_phone" : { "type" : "text" },
        "roles" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "uid" : { "type" : "integer" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "exclude" : {
          "status" : 0,
          "weight" : "-50",
          "settings" : { "fields" : { "name" : "", "values" : "" } }
        },
        "location" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "field_name" : "field_location" }
        },
        "search_api_alter_role_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "roles" : { "3" : "3" } }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_user_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_profile_address" : true,
              "field_profile_city" : true,
              "field_profile_entry" : true,
              "field_profile_name" : true,
              "field_profile_phone" : true,
              "field_profile_mail" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "field_profile_address" : true,
              "field_profile_city" : true,
              "field_profile_entry" : true,
              "field_profile_name" : true,
              "field_profile_phone" : true,
              "field_profile_mail" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "field_profile_address" : true,
              "field_profile_city" : true,
              "field_profile_entry" : true,
              "field_profile_name" : true,
              "field_profile_phone" : true,
              "field_profile_mail" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "field_profile_address" : true,
              "field_profile_city" : true,
              "field_profile_entry" : true,
              "field_profile_name" : true,
              "field_profile_phone" : true,
              "field_profile_mail" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "field_profile_address" : true,
              "field_profile_city" : true,
              "field_profile_entry" : true,
              "field_profile_name" : true,
              "field_profile_phone" : true,
              "field_profile_mail" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function ulf_skive_search_settings_default_search_api_server() {
  $items = array();
  $items['search_node'] = entity_import('search_api_server', '{
    "name" : "Search node",
    "machine_name" : "search_node",
    "description" : "",
    "class" : "search_api_search_node_service",
    "options" : {
      "host" : "https:\\/\\/search-node.ulfiaarhus.dk",
      "apikey" : "9ef93caf8d1425cbd34f60829c0336cb",
      "apikey_readonly" : "a75492dc301efd7a437f35aff9fa88cb"
    },
    "enabled" : "1"
  }');
  return $items;
}
