Leaflet Google Maps layer
========================================================================================================

Google maps layers for Leaflet thanks to @shramov and his Leaflet plugins code:
https://github.com/shramov/leaflet-plugins
https://github.com/shramov/leaflet-plugins/blob/master/layer/tile/Google.js

Leaflet plugins is required and it's downloaded automatically if you enable the module with drush.
There is a drush commnad to download the library in case you enable the module via the Web UI:
drush leaflet-plugins-download

In case you don't use drush, please do, but if you cannot install it manually to
sites/[yoursite-or-all]/libraries/leaflet-plugins directory so
sites/[yoursite-or-all]/libraries/leaflet-plugins/layer/tile/Google.js exists.

This module depends on Drupal Leaflet module (http://drupal.org/project/leaflet) in dev version which has this patch that
makes Leaflet a library:
http://drupal.org/node/1795912
