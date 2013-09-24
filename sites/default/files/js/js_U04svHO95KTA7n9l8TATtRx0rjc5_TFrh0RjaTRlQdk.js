
/**
 * @file
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Icon manager for getlocations.
 * Required for markers to operate properly.
 * For Google maps API v3
 *
 * Derived from gmap icons.js
 */

/**
 * Get the Icon corresponding to a setname / sequence.
 * There is only one Icon for each slot in the sequence.
 * The marker set wraps around when reaching the end of the sequence.
 */

(function ($) {

Drupal.getlocations = {};

Drupal.getlocations.getIcon = function (setname, sequence) {

  if (!setname) {
    return;
  }

  if (!this.gicons) {
    this.gicons = {};
  }

  // If no sequence, synthesise one.
  if (!sequence) {
    // @TODO make this per-map.
    if (!this.sequences) {
      this.sequences = {};
    }
    if (!this.sequences[setname]) {
      this.sequences[setname] = -1;
    }
    this.sequences[setname]++;
    sequence = this.sequences[setname];
  }

  if (!this.gicons[setname]) {
    if (!Drupal.getlocations.icons[setname]) {
      var aa = {'!b': setname};
      alert(Drupal.t('Request for invalid marker set !b', aa));
    }
    this.gicons[setname] = [];
    var q = Drupal.getlocations.icons[setname];
    var p;
    var t = [];
    for (var i = 0; i < q.sequence.length; i++) {
      p = Drupal.getlocations.iconpath + q.path;

      t.image =  new google.maps.MarkerImage(
        p + q.sequence[i].f,
        new google.maps.Size(q.sequence[i].w, q.sequence[i].h),
        new google.maps.Point(q.imagepoint1X, q.imagepoint1Y),
        new google.maps.Point(q.imagepoint2X, q.imagepoint2Y)
      );
      if (q.shadow.f !== '') {
        t.shadow = new google.maps.MarkerImage(
          p + q.shadow.f,
          new google.maps.Size(q.shadow.w, q.shadow.h),
          new google.maps.Point(q.shadowpoint1X, q.shadowpoint1Y),
          new google.maps.Point(q.shadowpoint2X, q.shadowpoint2Y)
        );
      }
      // turn string in shapecoords into array
      if (q.shapecoords !== '') {
        t.shape = { coord: q.shapecoords.split(','), type: q.shapetype };
      }

      // @@@ imageMap?
      this.gicons[setname][i] = t;
    }
    delete Drupal.getlocations.icons[setname];
  }
  // TODO: Random, other cycle methods.
  return this.gicons[setname][sequence % this.gicons[setname].length];

};

/**
 * JSON callback to set up the icon defs.
 * When doing the JSON call, the data comes back in a packed format.
 * We need to expand it and file it away in a more useful format.
 */
Drupal.getlocations.iconSetup = function () {
  Drupal.getlocations.icons = {};
  var m = Drupal.getlocations.icondata;
  var filef, filew, fileh, files;
  for (var path in m) {
    if (m.hasOwnProperty(path)) {
      // Reconstitute files array
      filef = m[path].f;
      filew = Drupal.getlocations.expandArray(m[path].w, filef.length);
      fileh = Drupal.getlocations.expandArray(m[path].h, filef.length);
      files = [];
      for (var i = 0; i < filef.length; i++) {
        files[i] = {f : filef[i], w : filew[i], h : fileh[i]};
      }

      for (var ini in m[path].i) {
        if (m[path].i.hasOwnProperty(ini)) {
          $.extend(Drupal.getlocations.icons, Drupal.getlocations.expandIconDef(m[path].i[ini], path, files));
        }
      }
    }
  }
};

/**
 * Expand a compressed array.
 * This will pad arr up to len using the last value of the old array.
 */
Drupal.getlocations.expandArray = function (arr, len) {
  var d = arr[0];
  for (var i = 0; i < len; i++) {
    if (!arr[i]) {
      arr[i] = d;
    }
    else {
      d = arr[i];
    }
  }
  return arr;
};

/**
 * Expand icon definition.
 * This helper function is the reverse of the packer function found in
 * getlocations_markerinfo.inc.
 */
Drupal.getlocations.expandIconDef = function (c, path, files) {

  var decomp = ['key', 'name', 'sequence',
    'imagepoint1X', 'imagepoint1Y', 'imagepoint2X', 'imagepoint2Y',
    'shadow', 'shadowpoint1X', 'shadowpoint1Y', 'shadowpoint2X', 'shadowpoint2Y',
    'shapecoords', 'shapetype'];

  var fallback = ['', '', [], 0, 0, 0, 0, {f: '', h: 0, w: 0}, 0, 0, 0, 0, '', ''];

  var imagerep = ['shadow'];

  var defaults = {};
  var sets = [];
  var i, j;
  // Part 1: Defaults / Markersets
  // Expand arrays and fill in missing ones with fallbacks
  for (i = 0; i < decomp.length; i++) {
    if (!c[0][i]) {
      c[0][i] = [ fallback[i] ];
    }
    c[0][i] = Drupal.getlocations.expandArray(c[0][i], c[0][0].length);
  }
  for (i = 0; i < c[0][0].length; i++) {
    for (j = 0; j < decomp.length; j++) {
      if (i === 0) {
        defaults[decomp[j]] = c[0][j][i];
      }
      else {
        if (!sets[i - 1]) {
          sets[i - 1] = {};
        }
        sets[i - 1][decomp[j]] = c[0][j][i];
      }
    }
  }
  for (i = 0; i < sets.length; i++) {
    for (j = 0; j < decomp.length; j++) {
      if (sets[i][decomp[j]] === fallback[j]) {
        sets[i][decomp[j]] = defaults[decomp[j]];
      }
    }
  }
  var icons = {};
  for (i = 0; i < sets.length; i++) {
    var key = sets[i].key;
    icons[key] = sets[i];
    icons[key].path = path;
    delete icons[key].key;
    delete sets[i];
    for (j = 0; j < icons[key].sequence.length; j++) {
      icons[key].sequence[j] = files[icons[key].sequence[j]];
    }
    for (j = 0; j < imagerep.length; j++) {
      if (typeof(icons[key][imagerep[j]]) === 'number') {
        icons[key][imagerep[j]] = files[icons[key][imagerep[j]]];
      }
    }
  }
  return icons;
};



/**
 * We attach ourselves if we find a map somewhere needing markers.
 * Note: Since we broadcast our ready event to all maps, it doesn't
 * matter which one we attached to!
 */

/*
Drupal.getlocations.addHandler('getlocations', function (elem) {
  var obj = this;

  obj.bind('init', function () {
    // Only expand once.
    if (!Drupal.getlocations.icons) {
      Drupal.getlocations.iconSetup();
    }
  });


  obj.bind('ready', function () {
    // Compatibility event.
    if (Drupal.getlocations.icondata) {
      obj.deferChange('iconsready', -1);
    }
  });

  if (!obj.vars.behavior.customicons) {
    // Provide icons to markers.
    obj.bind('preparemarker', function (marker) {
      marker.opts.icon = Drupal.getlocations.getIcon(marker.markername, marker.offset);
    });
  }


});

*/
}(jQuery));
;
// Getlocations marker image data.
Drupal.getlocations.iconpath = "\/";
Drupal.getlocations.icondata = {"\/various\/":{"f":[],"w":[],"h":[],"i":[]},"sites\/all\/libraries\/getlocations\/markers\/various\/":{"f":["shadow.png","360degrees.png","abduction.png","accesdenied.png","acupuncture.png","administration.png","administrativeboundary.png","aed-2.png","agritourism.png","aircraftcarrier.png","aircraftsmall.png","airport_apron.png","airport.png","airport_runway.png","airport_terminal.png","alien.png","alligator.png","amphitheater-2.png","amphitheater.png","anchorpier.png","animal-shelter-export.png","anniversary.png","ant-export.png","apartment-3.png","apple.png","aquarium.png","archery.png","arch.png","army.png","artgallery.png","atm-2.png","atv.png","audio.png","australianfootball.png","avalanche1.png","award.png","badminton-2.png","bags.png","bank.png","barbecue.png","barber.png","bar_coktail.png","bar_juice.png","bar.png","barrier.png","baseball.png","basketball.png","bats.png","battlefield.png","battleship-3.png","beach.png","beachvolleyball.png","beautifulview.png","beautysalon.png","bigcity.png","billiard-2.png","binoculars.png","birds-2.png","blast.png","boardercross.png","boat.png","bobsleigh.png","bomb.png","bowling.png","boxing.png","bread.png","brewery1.png","bridge_modern.png","bridge_old.png","bulldozer.png","bullfight.png","bunker-2-2.png","bus.png","busstop.png","bustour.png","butcher-2.png","butterfly-2.png","cabin-2.png","cablecar.png","cafetaria.png","calendar-3.png","campfire-2.png","camping-2.png","candy.png","canyon.png","caraccident.png","car.png","carrental.png","carwash.png","casino-2.png","castle-2.png","cathedral.png","catholicgrave.png","caution.png","cave-2.png","cctv.png","cemetary.png","chapel-2.png","chart-2.png","cheese.png","chemistry-2.png","chicken-2.png","childmuseum01.png","chiropractor.png","christmasmarket.png","church-2.png","cinema.png","circus.png","citysquare.png","citywalls.png","climbing.png","clock.png","closedroad.png","clothers_female.png","clothers_male.png","cloudy.png","cloudysunny.png","coffee.png","coins.png","comedyclub.png","comics.png","comment-map-icon.png","communitycentre.png","company.png","compost.png","computers.png","condominium.png","conference.png","congress.png","construction.png","contract.png","conveniencestore.png","convent-2.png","conversation-map-icon.png","corral.png","country.png","court.png","cowabduction.png","cow-export.png","craftstore.png","cramschool.png","cricket.png","crimescene.png","cromlech.png","cropcircles.png","cross-2.png","crossingguard.png","cruiseship.png","cup.png","curling-2.png","currencyexchange.png","customs.png","cycling_feed.png","cycling.png","cycling_sprint.png","dam.png","dance_class.png","dancinghall.png","database.png","daycare.png","deepseafishing.png","deer.png","dentist.png","departmentstore.png","desert-2.png","dinopark.png","direction_down.png","disability.png","diving.png","dogs_leash.png","dolphins.png","doublebendright.png","downloadicon.png","drinkingfountain.png","drinkingwater.png","drugstore.png","duck-export.png","earthquake-3.png","eggs.png","elephants.png","elevator_down.png","elevator.png","elevator_up.png","embassy.png","entrance.png","exit.png","expert.png","factory.png","fallingrocks.png","family.png","farm-2.png","farmstand.png","fastfood.png","female-2.png","ferriswheel.png","ferry.png","fetalalcoholsyndrom.png","field.png","fillingstation.png","findajob.png","finish.png","fireexstinguisher.png","fire-hydrant-2.png","firemen.png","fire.png","fireworks.png","firstaid.png","fishchips.png","fishingboat.png","fishing.png","fishingstore.png","fitness.png","fjord-2.png","flag-export.png","flood.png","flowers.png","folder-2.png","fooddeliveryservice.png","foodtruck.png","ford-2.png","forest2.png","forest.png","fossils.png","fountain-2.png","frog-2.png","fruits.png","gay-female.png","gay-male.png","geyser-2.png","ghosttown.png","gifts.png","glacier-2.png","golfing.png","gondola-2.png","gourmet_0star.png","grass.png","grocery.png","group-2.png","handball.png","hanggliding.png","harbor.png","hats.png","haybale.png","headstone-2.png","helicopter.png","highschool.png","highway.png","hiking.png","historicalquarter.png","homecenter.png","home.png","horseriding.png","hospital-building.png","hostel_0star.png","hotairbaloon.png","hotel_0star.png","hotspring.png","house.png","hunting.png","icecream.png","icehockey.png","iceskating.png","icy_road.png","indoor-arena.png","information.png","jacuzzi.png","japanese-food.png","japanese-lantern.png","japanese-sake.png","japanese-sweet-2.png","japanese-temple.png","jazzclub.png","jetfighter.png","jewelry.png","jewishgrave.png","jewishquarter.png","jogging.png","judo.png","karate.png","karting.png","kayaking.png","kebab.png","kiosk.png","kitesurfing.png","laboratory.png","lake.png","landfill.png","landmark.png","laundromat.png","levelcrossing.png","library.png","lifeguard-2.png","lighthouse-2.png","linedown.png","lingerie.png","liquor.png","lobster-export.png","lockerrental.png","lodging_0star.png","love_date.png","loveinterest.png","magicshow.png","mainroad.png","male-2.png","mall.png","map.png","market.png","massage.png","medicine.png","megalith.png","memorial.png","metronetwork.png","military.png","mine.png","mobilephonetower.png","modernmonument.png","moderntower.png","monkey-export.png","monument.png","mosquee.png","mosquito.png","motel-2.png","motorbike.png","motorcycle.png","mountain-pass-locator-diagonal-reverse-export.png","mountains.png","movierental.png","moving-walkway-enter-export.png","mural.png","museum_archeological.png","museum_art.png","museum_crafts.png","museum_industry.png","museum_naval.png","museum_openair.png","museum_science.png","museum_war.png","mushroom.png","music_choral.png","music_classical.png","music_hiphop.png","music_live.png","music.png","music_rock.png","nanny.png","ne_barn-2.png","newsagent.png","no-nuke-export.png","nordicski.png","notvisited.png","nursery.png","observatory.png","oilpumpjack.png","olympicsite.png","ophthalmologist.png","pagoda-2.png","paintball.png","paint.png","palace-2.png","palm-tree-export.png","panoramicview.png","paragliding.png","parkandride.png","parking-meter-export.png","parking.png","party-2.png","patisserie.png","peace.png","pedestriancrossing.png","penguin-2.png","pens.png","perfumery.png","petanque.png","petroglyphs-2.png","pets.png","phantom.png","phones.png","photography.png","photo.png","picnic-2.png","pig.png","pin-export.png","pirates.png","pizzaria.png","planecrash.png","planetarium-2.png","playground.png","pleasurepier.png","poker.png","police.png","postal.png","powerlinepole.png","poweroutage.png","powerplant.png","powersubstation.png","prayer.png","presentation.png","price-tag-export.png","printer-2.png","prison.png","publicart.png","pyramid.png","quadrifoglio.png","radar.png","radiation.png","rainy.png","rape.png","recycle.png","regroup.png","repair.png","rescue-2.png","resort.png","restaurant_african.png","restaurant_breakfast.png","restaurant_buffet.png","restaurant_chinese.png","restaurant_fish.png","restaurant_greek.png","restaurant_indian.png","restaurant_italian.png","restaurant_korean.png","restaurant_mediterranean.png","restaurant_mexican.png","restaurant.png","restaurant_romantic.png","restaurant_steakhouse.png","restaurant_tapas.png","restaurant_thai.png","restaurant_turkish.png","restaurant_vegetarian.png","revolt.png","riparianhabitat.png","roadtype_gravel.png","rockhouse.png","rodent.png","rollerskate.png","ropescourse.png","rowboat.png","rugbyfield.png","ruins-2.png","sailing.png","sandwich-2.png","sauna.png","sawmill-2.png","school.png","scubadiving.png","seals.png","segway.png","seniorsite.png","share.png","shark-export.png","shintoshrine.png","shipwreck.png","shoes.png","shooting.png","shore-2.png","shower.png","sight-2.png","signpost-2.png","sikh.png","skiing.png","skijump.png","skilifting.png","skull.png","sledge.png","sledgerental.png","sledge_summer.png","smallcity.png","smiley_happy.png","smoking.png","snail.png","snakes.png","sneakers.png","snorkeling.png","snowboarding.png","snowmobiling.png","snowpark_arc.png","snowshoeing.png","snowy-2.png","soccer.png","solarenergy.png","spaceport-2.png","spa.png","speed_50.png","speedhump.png","speedriding.png","spelunking.png","spider.png","sportutilityvehicle.png","squash-2.png","stadium.png","star-3.png","stargate-raw.png","statue-2.png","steamtrain.png","stop.png","strike.png","submarine-2.png","sugar-shack.png","summercamp.png","sumo-2.png","sunny.png","supermarket.png","surfacelift.png","surfing.png","surveying-2.png","swimming.png","synagogue-2.png","taekwondo-2.png","tailor.png","takeaway.png","taxi.png","taxiway.png","teahouse.png","tebletennis.png","telephone.png","temple-2.png","templehindu.png","tennis.png","terrace.png","textiles.png","text.png","theater.png","theft.png","themepark.png","therapy.png","thunderstorm.png","tiger-2.png","tires.png","toilets.png","tollstation.png","tools.png","tornado-2.png","torture.png","tower.png","toys.png","trafficcamera.png","trafficlight.png","train.png","tramway.png","trash.png","treedown.png","trolley.png","truck3.png","tsunami.png","tunnel.png","tweet.png","ufo.png","underground.png","university.png","u-pick_stand.png","usfootball.png","van.png","vespa.png","veterinary.png","videogames.png","video.png","villa.png","vineyard-2.png","volcano-2.png","volleyball.png","waiting.png","walkingtour.png","war.png","watercraft.png","waterfall-2.png","watermill-2.png","waterpark.png","waterskiing.png","watertower.png","waterwell.png","waterwellpump.png","webcam.png","wedding.png","weights.png","wetlands.png","whale-2.png","wifi.png","wiki-export.png","wildlifecrossing.png","wind-2.png","windmill-2.png","windsurfing.png","windturbine.png","winebar.png","winetasting.png","workoffice.png","worldheritagesite.png","world.png","wrestling-2.png","yoga.png","yooner.png","youthhostel.png","zoom.png","zoo.png"],"w":[54,32],"h":[37],"i":[[[["defaults","various 360degrees","various abduction","various accesdenied","various acupuncture","various administration","various administrativeboundary","various aed-2","various agritourism","various aircraftcarrier","various aircraftsmall","various airport_apron","various airport","various airport_runway","various airport_terminal","various alien","various alligator","various amphitheater-2","various amphitheater","various anchorpier","various animal-shelter-export","various anniversary","various ant-export","various apartment-3","various apple","various aquarium","various archery","various arch","various army","various artgallery","various atm-2","various atv","various audio","various australianfootball","various avalanche1","various award","various badminton-2","various bags","various bank","various barbecue","various barber","various bar_coktail","various bar_juice","various bar","various barrier","various baseball","various basketball","various bats","various battlefield","various battleship-3","various beach","various beachvolleyball","various beautifulview","various beautysalon","various bigcity","various billiard-2","various binoculars","various birds-2","various blast","various boardercross","various boat","various bobsleigh","various bomb","various bowling","various boxing","various bread","various brewery1","various bridge_modern","various bridge_old","various bulldozer","various bullfight","various bunker-2-2","various bus","various busstop","various bustour","various butcher-2","various butterfly-2","various cabin-2","various cablecar","various cafetaria","various calendar-3","various campfire-2","various camping-2","various candy","various canyon","various caraccident","various car","various carrental","various carwash","various casino-2","various castle-2","various cathedral","various catholicgrave","various caution","various cave-2","various cctv","various cemetary","various chapel-2","various chart-2","various cheese","various chemistry-2","various chicken-2","various childmuseum01","various chiropractor","various christmasmarket","various church-2","various cinema","various circus","various citysquare","various citywalls","various climbing","various clock","various closedroad","various clothers_female","various clothers_male","various cloudy","various cloudysunny","various coffee","various coins","various comedyclub","various comics","various comment-map-icon","various communitycentre","various company","various compost","various computers","various condominium","various conference","various congress","various construction","various contract","various conveniencestore","various convent-2","various conversation-map-icon","various corral","various country","various court","various cowabduction","various cow-export","various craftstore","various cramschool","various cricket","various crimescene","various cromlech","various cropcircles","various cross-2","various crossingguard","various cruiseship","various cup","various curling-2","various currencyexchange","various customs","various cycling_feed","various cycling","various cycling_sprint","various dam","various dance_class","various dancinghall","various database","various daycare","various deepseafishing","various deer","various dentist","various departmentstore","various desert-2","various dinopark","various direction_down","various disability","various diving","various dogs_leash","various dolphins","various doublebendright","various downloadicon","various drinkingfountain","various drinkingwater","various drugstore","various duck-export","various earthquake-3","various eggs","various elephants","various elevator_down","various elevator","various elevator_up","various embassy","various entrance","various exit","various expert","various factory","various fallingrocks","various family","various farm-2","various farmstand","various fastfood","various female-2","various ferriswheel","various ferry","various fetalalcoholsyndrom","various field","various fillingstation","various findajob","various finish","various fireexstinguisher","various fire-hydrant-2","various firemen","various fire","various fireworks","various firstaid","various fishchips","various fishingboat","various fishing","various fishingstore","various fitness","various fjord-2","various flag-export","various flood","various flowers","various folder-2","various fooddeliveryservice","various foodtruck","various ford-2","various forest2","various forest","various fossils","various fountain-2","various frog-2","various fruits","various gay-female","various gay-male","various geyser-2","various ghosttown","various gifts","various glacier-2","various golfing","various gondola-2","various gourmet_0star","various grass","various grocery","various group-2","various handball","various hanggliding","various harbor","various hats","various haybale","various headstone-2","various helicopter","various highschool","various highway","various hiking","various historicalquarter","various homecenter","various home","various horseriding","various hospital-building","various hostel_0star","various hotairbaloon","various hotel_0star","various hotspring","various house","various hunting","various icecream","various icehockey","various iceskating","various icy_road","various indoor-arena","various information","various jacuzzi","various japanese-food","various japanese-lantern","various japanese-sake","various japanese-sweet-2","various japanese-temple","various jazzclub","various jetfighter","various jewelry","various jewishgrave","various jewishquarter","various jogging","various judo","various karate","various karting","various kayaking","various kebab","various kiosk","various kitesurfing","various laboratory","various lake","various landfill","various landmark","various laundromat","various levelcrossing","various library","various lifeguard-2","various lighthouse-2","various linedown","various lingerie","various liquor","various lobster-export","various lockerrental","various lodging_0star","various love_date","various loveinterest","various magicshow","various mainroad","various male-2","various mall","various map","various market","various massage","various medicine","various megalith","various memorial","various metronetwork","various military","various mine","various mobilephonetower","various modernmonument","various moderntower","various monkey-export","various monument","various mosquee","various mosquito","various motel-2","various motorbike","various motorcycle","various mountain-pass-locator-diagonal-reverse-export","various mountains","various movierental","various moving-walkway-enter-export","various mural","various museum_archeological","various museum_art","various museum_crafts","various museum_industry","various museum_naval","various museum_openair","various museum_science","various museum_war","various mushroom","various music_choral","various music_classical","various music_hiphop","various music_live","various music","various music_rock","various nanny","various ne_barn-2","various newsagent","various no-nuke-export","various nordicski","various notvisited","various nursery","various observatory","various oilpumpjack","various olympicsite","various ophthalmologist","various pagoda-2","various paintball","various paint","various palace-2","various palm-tree-export","various panoramicview","various paragliding","various parkandride","various parking-meter-export","various parking","various party-2","various patisserie","various peace","various pedestriancrossing","various penguin-2","various pens","various perfumery","various petanque","various petroglyphs-2","various pets","various phantom","various phones","various photography","various photo","various picnic-2","various pig","various pin-export","various pirates","various pizzaria","various planecrash","various planetarium-2","various playground","various pleasurepier","various poker","various police","various postal","various powerlinepole","various poweroutage","various powerplant","various powersubstation","various prayer","various presentation","various price-tag-export","various printer-2","various prison","various publicart","various pyramid","various quadrifoglio","various radar","various radiation","various rainy","various rape","various recycle","various regroup","various repair","various rescue-2","various resort","various restaurant_african","various restaurant_breakfast","various restaurant_buffet","various restaurant_chinese","various restaurant_fish","various restaurant_greek","various restaurant_indian","various restaurant_italian","various restaurant_korean","various restaurant_mediterranean","various restaurant_mexican","various restaurant","various restaurant_romantic","various restaurant_steakhouse","various restaurant_tapas","various restaurant_thai","various restaurant_turkish","various restaurant_vegetarian","various revolt","various riparianhabitat","various roadtype_gravel","various rockhouse","various rodent","various rollerskate","various ropescourse","various rowboat","various rugbyfield","various ruins-2","various sailing","various sandwich-2","various sauna","various sawmill-2","various school","various scubadiving","various seals","various segway","various seniorsite","various share","various shark-export","various shintoshrine","various shipwreck","various shoes","various shooting","various shore-2","various shower","various sight-2","various signpost-2","various sikh","various skiing","various skijump","various skilifting","various skull","various sledge","various sledgerental","various sledge_summer","various smallcity","various smiley_happy","various smoking","various snail","various snakes","various sneakers","various snorkeling","various snowboarding","various snowmobiling","various snowpark_arc","various snowshoeing","various snowy-2","various soccer","various solarenergy","various spaceport-2","various spa","various speed_50","various speedhump","various speedriding","various spelunking","various spider","various sportutilityvehicle","various squash-2","various stadium","various star-3","various stargate-raw","various statue-2","various steamtrain","various stop","various strike","various submarine-2","various sugar-shack","various summercamp","various sumo-2","various sunny","various supermarket","various surfacelift","various surfing","various surveying-2","various swimming","various synagogue-2","various taekwondo-2","various tailor","various takeaway","various taxi","various taxiway","various teahouse","various tebletennis","various telephone","various temple-2","various templehindu","various tennis","various terrace","various textiles","various text","various theater","various theft","various themepark","various therapy","various thunderstorm","various tiger-2","various tires","various toilets","various tollstation","various tools","various tornado-2","various torture","various tower","various toys","various trafficcamera","various trafficlight","various train","various tramway","various trash","various treedown","various trolley","various truck3","various tsunami","various tunnel","various tweet","various ufo","various underground","various university","various u-pick_stand","various usfootball","various van","various vespa","various veterinary","various videogames","various video","various villa","various vineyard-2","various volcano-2","various volleyball","various waiting","various walkingtour","various war","various watercraft","various waterfall-2","various watermill-2","various waterpark","various waterskiing","various watertower","various waterwell","various waterwellpump","various webcam","various wedding","various weights","various wetlands","various whale-2","various wifi","various wiki-export","various wildlifecrossing","various wind-2","various windmill-2","various windsurfing","various windturbine","various winebar","various winetasting","various workoffice","various worldheritagesite","various world","various wrestling-2","various yoga","various yooner","various youthhostel","various zoom","various zoo"],["","various 360degrees","various abduction","various accesdenied","various acupuncture","various administration","various administrativeboundary","various aed-2","various agritourism","various aircraftcarrier","various aircraftsmall","various airport_apron","various airport","various airport_runway","various airport_terminal","various alien","various alligator","various amphitheater-2","various amphitheater","various anchorpier","various animal-shelter-export","various anniversary","various ant-export","various apartment-3","various apple","various aquarium","various archery","various arch","various army","various artgallery","various atm-2","various atv","various audio","various australianfootball","various avalanche1","various award","various badminton-2","various bags","various bank","various barbecue","various barber","various bar_coktail","various bar_juice","various bar","various barrier","various baseball","various basketball","various bats","various battlefield","various battleship-3","various beach","various beachvolleyball","various beautifulview","various beautysalon","various bigcity","various billiard-2","various binoculars","various birds-2","various blast","various boardercross","various boat","various bobsleigh","various bomb","various bowling","various boxing","various bread","various brewery1","various bridge_modern","various bridge_old","various bulldozer","various bullfight","various bunker-2-2","various bus","various busstop","various bustour","various butcher-2","various butterfly-2","various cabin-2","various cablecar","various cafetaria","various calendar-3","various campfire-2","various camping-2","various candy","various canyon","various caraccident","various car","various carrental","various carwash","various casino-2","various castle-2","various cathedral","various catholicgrave","various caution","various cave-2","various cctv","various cemetary","various chapel-2","various chart-2","various cheese","various chemistry-2","various chicken-2","various childmuseum01","various chiropractor","various christmasmarket","various church-2","various cinema","various circus","various citysquare","various citywalls","various climbing","various clock","various closedroad","various clothers_female","various clothers_male","various cloudy","various cloudysunny","various coffee","various coins","various comedyclub","various comics","various comment-map-icon","various communitycentre","various company","various compost","various computers","various condominium","various conference","various congress","various construction","various contract","various conveniencestore","various convent-2","various conversation-map-icon","various corral","various country","various court","various cowabduction","various cow-export","various craftstore","various cramschool","various cricket","various crimescene","various cromlech","various cropcircles","various cross-2","various crossingguard","various cruiseship","various cup","various curling-2","various currencyexchange","various customs","various cycling_feed","various cycling","various cycling_sprint","various dam","various dance_class","various dancinghall","various database","various daycare","various deepseafishing","various deer","various dentist","various departmentstore","various desert-2","various dinopark","various direction_down","various disability","various diving","various dogs_leash","various dolphins","various doublebendright","various downloadicon","various drinkingfountain","various drinkingwater","various drugstore","various duck-export","various earthquake-3","various eggs","various elephants","various elevator_down","various elevator","various elevator_up","various embassy","various entrance","various exit","various expert","various factory","various fallingrocks","various family","various farm-2","various farmstand","various fastfood","various female-2","various ferriswheel","various ferry","various fetalalcoholsyndrom","various field","various fillingstation","various findajob","various finish","various fireexstinguisher","various fire-hydrant-2","various firemen","various fire","various fireworks","various firstaid","various fishchips","various fishingboat","various fishing","various fishingstore","various fitness","various fjord-2","various flag-export","various flood","various flowers","various folder-2","various fooddeliveryservice","various foodtruck","various ford-2","various forest2","various forest","various fossils","various fountain-2","various frog-2","various fruits","various gay-female","various gay-male","various geyser-2","various ghosttown","various gifts","various glacier-2","various golfing","various gondola-2","various gourmet_0star","various grass","various grocery","various group-2","various handball","various hanggliding","various harbor","various hats","various haybale","various headstone-2","various helicopter","various highschool","various highway","various hiking","various historicalquarter","various homecenter","various home","various horseriding","various hospital-building","various hostel_0star","various hotairbaloon","various hotel_0star","various hotspring","various house","various hunting","various icecream","various icehockey","various iceskating","various icy_road","various indoor-arena","various information","various jacuzzi","various japanese-food","various japanese-lantern","various japanese-sake","various japanese-sweet-2","various japanese-temple","various jazzclub","various jetfighter","various jewelry","various jewishgrave","various jewishquarter","various jogging","various judo","various karate","various karting","various kayaking","various kebab","various kiosk","various kitesurfing","various laboratory","various lake","various landfill","various landmark","various laundromat","various levelcrossing","various library","various lifeguard-2","various lighthouse-2","various linedown","various lingerie","various liquor","various lobster-export","various lockerrental","various lodging_0star","various love_date","various loveinterest","various magicshow","various mainroad","various male-2","various mall","various map","various market","various massage","various medicine","various megalith","various memorial","various metronetwork","various military","various mine","various mobilephonetower","various modernmonument","various moderntower","various monkey-export","various monument","various mosquee","various mosquito","various motel-2","various motorbike","various motorcycle","various mountain-pass-locator-diagonal-reverse-export","various mountains","various movierental","various moving-walkway-enter-export","various mural","various museum_archeological","various museum_art","various museum_crafts","various museum_industry","various museum_naval","various museum_openair","various museum_science","various museum_war","various mushroom","various music_choral","various music_classical","various music_hiphop","various music_live","various music","various music_rock","various nanny","various ne_barn-2","various newsagent","various no-nuke-export","various nordicski","various notvisited","various nursery","various observatory","various oilpumpjack","various olympicsite","various ophthalmologist","various pagoda-2","various paintball","various paint","various palace-2","various palm-tree-export","various panoramicview","various paragliding","various parkandride","various parking-meter-export","various parking","various party-2","various patisserie","various peace","various pedestriancrossing","various penguin-2","various pens","various perfumery","various petanque","various petroglyphs-2","various pets","various phantom","various phones","various photography","various photo","various picnic-2","various pig","various pin-export","various pirates","various pizzaria","various planecrash","various planetarium-2","various playground","various pleasurepier","various poker","various police","various postal","various powerlinepole","various poweroutage","various powerplant","various powersubstation","various prayer","various presentation","various price-tag-export","various printer-2","various prison","various publicart","various pyramid","various quadrifoglio","various radar","various radiation","various rainy","various rape","various recycle","various regroup","various repair","various rescue-2","various resort","various restaurant_african","various restaurant_breakfast","various restaurant_buffet","various restaurant_chinese","various restaurant_fish","various restaurant_greek","various restaurant_indian","various restaurant_italian","various restaurant_korean","various restaurant_mediterranean","various restaurant_mexican","various restaurant","various restaurant_romantic","various restaurant_steakhouse","various restaurant_tapas","various restaurant_thai","various restaurant_turkish","various restaurant_vegetarian","various revolt","various riparianhabitat","various roadtype_gravel","various rockhouse","various rodent","various rollerskate","various ropescourse","various rowboat","various rugbyfield","various ruins-2","various sailing","various sandwich-2","various sauna","various sawmill-2","various school","various scubadiving","various seals","various segway","various seniorsite","various share","various shark-export","various shintoshrine","various shipwreck","various shoes","various shooting","various shore-2","various shower","various sight-2","various signpost-2","various sikh","various skiing","various skijump","various skilifting","various skull","various sledge","various sledgerental","various sledge_summer","various smallcity","various smiley_happy","various smoking","various snail","various snakes","various sneakers","various snorkeling","various snowboarding","various snowmobiling","various snowpark_arc","various snowshoeing","various snowy-2","various soccer","various solarenergy","various spaceport-2","various spa","various speed_50","various speedhump","various speedriding","various spelunking","various spider","various sportutilityvehicle","various squash-2","various stadium","various star-3","various stargate-raw","various statue-2","various steamtrain","various stop","various strike","various submarine-2","various sugar-shack","various summercamp","various sumo-2","various sunny","various supermarket","various surfacelift","various surfing","various surveying-2","various swimming","various synagogue-2","various taekwondo-2","various tailor","various takeaway","various taxi","various taxiway","various teahouse","various tebletennis","various telephone","various temple-2","various templehindu","various tennis","various terrace","various textiles","various text","various theater","various theft","various themepark","various therapy","various thunderstorm","various tiger-2","various tires","various toilets","various tollstation","various tools","various tornado-2","various torture","various tower","various toys","various trafficcamera","various trafficlight","various train","various tramway","various trash","various treedown","various trolley","various truck3","various tsunami","various tunnel","various tweet","various ufo","various underground","various university","various u-pick_stand","various usfootball","various van","various vespa","various veterinary","various videogames","various video","various villa","various vineyard-2","various volcano-2","various volleyball","various waiting","various walkingtour","various war","various watercraft","various waterfall-2","various watermill-2","various waterpark","various waterskiing","various watertower","various waterwell","various waterwellpump","various webcam","various wedding","various weights","various wetlands","various whale-2","various wifi","various wiki-export","various wildlifecrossing","various wind-2","various windmill-2","various windsurfing","various windturbine","various winebar","various winetasting","various workoffice","various worldheritagesite","various world","various wrestling-2","various yoga","various yooner","various youthhostel","various zoom","various zoo"],[[],[1],[2],[3],[4],[5],[6],[7],[8],[9],[10],[11],[12],[13],[14],[15],[16],[17],[18],[19],[20],[21],[22],[23],[24],[25],[26],[27],[28],[29],[30],[31],[32],[33],[34],[35],[36],[37],[38],[39],[40],[41],[42],[43],[44],[45],[46],[47],[48],[49],[50],[51],[52],[53],[54],[55],[56],[57],[58],[59],[60],[61],[62],[63],[64],[65],[66],[67],[68],[69],[70],[71],[72],[73],[74],[75],[76],[77],[78],[79],[80],[81],[82],[83],[84],[85],[86],[87],[88],[89],[90],[91],[92],[93],[94],[95],[96],[97],[98],[99],[100],[101],[102],[103],[104],[105],[106],[107],[108],[109],[110],[111],[112],[113],[114],[115],[116],[117],[118],[119],[120],[121],[122],[123],[124],[125],[126],[127],[128],[129],[130],[131],[132],[133],[134],[135],[136],[137],[138],[139],[140],[141],[142],[143],[144],[145],[146],[147],[148],[149],[150],[151],[152],[153],[154],[155],[156],[157],[158],[159],[160],[161],[162],[163],[164],[165],[166],[167],[168],[169],[170],[171],[172],[173],[174],[175],[176],[177],[178],[179],[180],[181],[182],[183],[184],[185],[186],[187],[188],[189],[190],[191],[192],[193],[194],[195],[196],[197],[198],[199],[200],[201],[202],[203],[204],[205],[206],[207],[208],[209],[210],[211],[212],[213],[214],[215],[216],[217],[218],[219],[220],[221],[222],[223],[224],[225],[226],[227],[228],[229],[230],[231],[232],[233],[234],[235],[236],[237],[238],[239],[240],[241],[242],[243],[244],[245],[246],[247],[248],[249],[250],[251],[252],[253],[254],[255],[256],[257],[258],[259],[260],[261],[262],[263],[264],[265],[266],[267],[268],[269],[270],[271],[272],[273],[274],[275],[276],[277],[278],[279],[280],[281],[282],[283],[284],[285],[286],[287],[288],[289],[290],[291],[292],[293],[294],[295],[296],[297],[298],[299],[300],[301],[302],[303],[304],[305],[306],[307],[308],[309],[310],[311],[312],[313],[314],[315],[316],[317],[318],[319],[320],[321],[322],[323],[324],[325],[326],[327],[328],[329],[330],[331],[332],[333],[334],[335],[336],[337],[338],[339],[340],[341],[342],[343],[344],[345],[346],[347],[348],[349],[350],[351],[352],[353],[354],[355],[356],[357],[358],[359],[360],[361],[362],[363],[364],[365],[366],[367],[368],[369],[370],[371],[372],[373],[374],[375],[376],[377],[378],[379],[380],[381],[382],[383],[384],[385],[386],[387],[388],[389],[390],[391],[392],[393],[394],[395],[396],[397],[398],[399],[400],[401],[402],[403],[404],[405],[406],[407],[408],[409],[410],[411],[412],[413],[414],[415],[416],[417],[418],[419],[420],[421],[422],[423],[424],[425],[426],[427],[428],[429],[430],[431],[432],[433],[434],[435],[436],[437],[438],[439],[440],[441],[442],[443],[444],[445],[446],[447],[448],[449],[450],[451],[452],[453],[454],[455],[456],[457],[458],[459],[460],[461],[462],[463],[464],[465],[466],[467],[468],[469],[470],[471],[472],[473],[474],[475],[476],[477],[478],[479],[480],[481],[482],[483],[484],[485],[486],[487],[488],[489],[490],[491],[492],[493],[494],[495],[496],[497],[498],[499],[500],[501],[502],[503],[504],[505],[506],[507],[508],[509],[510],[511],[512],[513],[514],[515],[516],[517],[518],[519],[520],[521],[522],[523],[524],[525],[526],[527],[528],[529],[530],[531],[532],[533],[534],[535],[536],[537],[538],[539],[540],[541],[542],[543],[544],[545],[546],[547],[548],[549],[550],[551],[552],[553],[554],[555],[556],[557],[558],[559],[560],[561],[562],[563],[564],[565],[566],[567],[568],[569],[570],[571],[572],[573],[574],[575],[576],[577],[578],[579],[580],[581],[582],[583],[584],[585],[586],[587],[588],[589],[590],[591],[592],[593],[594]],[0],[0],[16,0],[37,0],[0],[0],[0],[16,0],[37,0],["0,0,32,37",""],["rect",""]],[[],[],[],[],[],[],[],[],[],[],[],[],[],[]]]]},"\/small\/":{"f":[],"w":[],"h":[],"i":[]},"sites\/all\/libraries\/getlocations\/markers\/small\/":{"f":["shadow.png","red.png","bred.png","orange.png","pyellow.png","yellow.png","pgreen.png","green.png","dgreen.png","fgreen.png","pblue.png","lblue.png","blue.png","dblue.png","purple.png","pink.png","bpink.png","brown.png","white.png","lgray.png","gray.png","black.png","altblue.png","altred.png"],"w":[26,12],"h":[20],"i":[[[["defaults","small red","small bred","small orange","small pyellow","small yellow","small pgreen","small green","small dgreen","small fgreen","small pblue","small lblue","small blue","small dblue","small purple","small pink","small bpink","small brown","small white","small lgray","small gray","small black","alt small blue","alt small red"],["","Small Red","Small Bright red","Small Orange","Small Pale Yellow","Small Yellow","Small Pale Green","Small Green","Small Dark Green","Small Flouro Green","Small Pale Blue","Small Light Blue","Small Blue","Small Dark Blue","Small Purple","Small Pink","Small Bright Pink","Small Brown","Small White","Small Light Gray","Small Gray","Small Black","Small Blue (Alternate)","Small Red (Alternate)"],[[],[1],[2],[3],[4],[5],[6],[7],[8],[9],[10],[11],[12],[13],[14],[15],[16],[17],[18],[19],[20],[21],[22],[23]],[0],[0],[6,0],[20,0],[0],[0],[0],[6,0],[20,0],["0,0,12,20",""],["rect",""]],[[],[],[],[],[],[],[],[],[],[],[],[],[],[]]]]},"\/misc\/":{"f":[],"w":[],"h":[],"i":[]},"sites\/all\/libraries\/getlocations\/markers\/misc\/":{"f":["shadow.png","blank.png","cluster.png","drupal.png","route1.png","route2.png","vertex.png"],"w":[40,20,20,20,20,20,8],"h":[34,34,34,34,34,34,8],"i":[[[["defaults","blank","cluster","drupal","route1","route2","vertex"],["","Blank","Cluster","Drupal","Route 1","Route 2","Line Vertex"],[[],[1],[2],[3],[4],[5],[6]],[0],[0],[10,0,0,0,0,0,4],[34,0,0,0,0,0,8],[0],[0],[0],[10,0],[34,0],["0,0,20,34","","","","","","0,0,16,16"],["rect","","","","","","rect"]],[[],[],[],[],[],[],[],[],[],[],[],[],[],[]]]]},"\/markers_italo\/":{"f":[],"w":[],"h":[],"i":[]},"sites\/all\/libraries\/getlocations\/markers\/markers_italo\/":{"f":["shadow.png","red_Marker.png"],"w":[52,36],"h":[42,49],"i":[[[["defaults","marker_italo red"],["","marker_italo Red"],[[],[1]],[0],[0],[14,0],[42,0],[0],[0],[0],[14,0],[42,0],["0,0,42,52",""],["rect",""]],[[],[],[],[],[],[],[],[],[],[],[],[],[],[]]]]},"\/flat\/":{"f":[],"w":[],"h":[],"i":[]},"sites\/all\/libraries\/getlocations\/markers\/flat\/":{"f":["x.png"],"w":[16],"h":[16],"i":[[[["defaults","treasure"],["","X marks the spot"],[[],[0]],[0],[0],[8,0],[8,0]],[[],[],[],[],[],[],[],[],[],[],[],[],[],[]]]]},"\/days\/":{"f":[],"w":[],"h":[],"i":[]},"sites\/all\/libraries\/getlocations\/markers\/days\/":{"f":["shadow.png","marker_sunday.png","marker_monday.png","marker_tuesday.png","marker_wednesday.png","marker_thursday.png","marker_friday.png","marker_saturday.png"],"w":[40,20],"h":[34],"i":[[[["defaults","sunday","monday","tuesday","wednesday","thursday","friday","saturday"],["","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"],[[],[1],[2],[3],[4],[5],[6],[7]],[0],[0],[10,0],[34,0],[0],[0],[0],[10,0],[34,0],["0,0,20,34",""],["rect",""]],[[],[],[],[],[],[],[],[],[],[],[],[],[],[]]]]},"\/colors\/":{"f":[],"w":[],"h":[],"i":[]},"sites\/all\/libraries\/getlocations\/markers\/colors\/":{"f":["shadow.png","blue.png","gray.png","green.png","lblue.png","orange.png","pink.png","purple.png","white.png","yellow.png"],"w":[40,20],"h":[34],"i":[[[["defaults","blue","gray","green","lblue","orange","pink","purple","white","yellow"],["","Blue","Gray","Green","Light Blue","Orange","Pink","Purple","White","Yellow"],[[],[1],[2],[3],[4],[5],[6],[7],[8],[9]],[0],[0],[10,0],[34,0],[0],[0],[0],[10,0],[34,0],["0,0,20,34",""],["rect",""]],[[],[],[],[],[],[],[],[],[],[],[],[],[],[]]]]},"\/circular\/":{"f":[],"w":[],"h":[],"i":[]},"sites\/all\/libraries\/getlocations\/markers\/circular\/":{"f":["shadow.png","add.png","arrow_down.png","arrow_left.png","arrow_right.png","arrows_4_way.png","arrows_east_west.png","arrows_north_east.png","arrows_north_south.png","arrows_south_west.png","arrow_up.png","at.png","book.png","broadcast.png","bulb.png","bullet_black.png","bullet_blue.png","bullet_green.png","bullet_red.png","bullet_yellow.png","cancel.png","cart.png","cd.png","clock.png","cog.png","comment.png","comments.png","copy.png","copyright.png","currency_eur.png","currency_gbp.png","currency_jpn.png","currency_usd.png","cut.png","delete.png","edit.png","element_clouds.png","element_fire.png","element_lightning.png","element_rain_clouds.png","element_sun_cloud.png","element_sun.png","element_water.png","email.png","eye.png","fast_forward.png","flag_black.png","flag_blue.png","flag_green.png","flag_red.png","flag_yellow.png","folder_close.png","folder_document.png","folder_open.png","folder.png","heart_black.png","heart_blue.png","heart_green.png","heart_red.png","heart_yellow.png","help.png","home.png","hourglass.png","information.png","key.png","magnify_minus.png","magnify_plus.png","magnify.png","minus.png","moon.png","music.png","new.png","no.png","omega.png","padlock_closed.png","padlock_open.png","paperclip.png","paste.png","pause.png","phone.png","pie_chart.png","play.png","pointer.png","power_off.png","power_on.png","print.png","puzzle.png","quote.png","refresh.png","rewind.png","rss.png","save.png","share_this.png","smiley_big_grin.png","smiley_flat.png","smiley_frown.png","smiley_smile.png","smiley_tounge.png","smiley_wink.png","speaker_off.png","speaker_on.png","star_black.png","star_blue.png","star_green.png","star_red.png","star_yellow.png","stop.png","tag_black.png","tag_blue.png","tag_green.png","tag_red.png","tag_yellow.png","turn_left.png","turn_right.png","user.png","warning.png","world.png","yes.png"],"w":[28,16,16,16,16,16,16,16,16,16,16,16,16,16,16,6,6,6,18,6,16],"h":[16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,6,6,6,18,6,16],"i":[[[["defaults","circular add","circular arrow_down","circular arrow_left","circular arrow_right","circular arrows_4_way","circular arrows_east_west","circular arrows_north_east","circular arrows_north_south","circular arrows_south_west","circular arrow_up","circular at","circular book","circular broadcast","circular bulb","circular bullet_black","circular bullet_blue","circular bullet_green","circular bullet_red","circular bullet_yellow","circular cancel","circular cart","circular cd","circular clock","circular cog","circular comment","circular comments","circular copy","circular copyright","circular currency_eur","circular currency_gbp","circular currency_jpn","circular currency_usd","circular cut","circular delete","circular edit","circular element_clouds","circular element_fire","circular element_lightning","circular element_rain_clouds","circular element_sun_cloud","circular element_sun","circular element_water","circular email","circular eye","circular fast_forward","circular flag_black","circular flag_blue","circular flag_green","circular flag_red","circular flag_yellow","circular folder_close","circular folder_document","circular folder_open","circular folder","circular heart_black","circular heart_blue","circular heart_green","circular heart_red","circular heart_yellow","circular help","circular home","circular hourglass","circular information","circular key","circular magnify_minus","circular magnify_plus","circular magnify","circular minus","circular moon","circular music","circular new","circular no","circular omega","circular padlock_closed","circular padlock_open","circular paperclip","circular paste","circular pause","circular phone","circular pie_chart","circular play","circular pointer","circular power_off","circular power_on","circular print","circular puzzle","circular quote","circular refresh","circular rewind","circular rss","circular save","circular share_this","circular smiley_big_grin","circular smiley_flat","circular smiley_frown","circular smiley_smile","circular smiley_tounge","circular smiley_wink","circular speaker_off","circular speaker_on","circular star_black","circular star_blue","circular star_green","circular star_red","circular star_yellow","circular stop","circular tag_black","circular tag_blue","circular tag_green","circular tag_red","circular tag_yellow","circular turn_left","circular turn_right","circular user","circular warning","circular world","circular yes"],["","circular add","circular arrow_down","circular arrow_left","circular arrow_right","circular arrows_4_way","circular arrows_east_west","circular arrows_north_east","circular arrows_north_south","circular arrows_south_west","circular arrow_up","circular at","circular book","circular broadcast","circular bulb","circular bullet_black","circular bullet_blue","circular bullet_green","circular bullet_red","circular bullet_yellow","circular cancel","circular cart","circular cd","circular clock","circular cog","circular comment","circular comments","circular copy","circular copyright","circular currency_eur","circular currency_gbp","circular currency_jpn","circular currency_usd","circular cut","circular delete","circular edit","circular element_clouds","circular element_fire","circular element_lightning","circular element_rain_clouds","circular element_sun_cloud","circular element_sun","circular element_water","circular email","circular eye","circular fast_forward","circular flag_black","circular flag_blue","circular flag_green","circular flag_red","circular flag_yellow","circular folder_close","circular folder_document","circular folder_open","circular folder","circular heart_black","circular heart_blue","circular heart_green","circular heart_red","circular heart_yellow","circular help","circular home","circular hourglass","circular information","circular key","circular magnify_minus","circular magnify_plus","circular magnify","circular minus","circular moon","circular music","circular new","circular no","circular omega","circular padlock_closed","circular padlock_open","circular paperclip","circular paste","circular pause","circular phone","circular pie_chart","circular play","circular pointer","circular power_off","circular power_on","circular print","circular puzzle","circular quote","circular refresh","circular rewind","circular rss","circular save","circular share_this","circular smiley_big_grin","circular smiley_flat","circular smiley_frown","circular smiley_smile","circular smiley_tounge","circular smiley_wink","circular speaker_off","circular speaker_on","circular star_black","circular star_blue","circular star_green","circular star_red","circular star_yellow","circular stop","circular tag_black","circular tag_blue","circular tag_green","circular tag_red","circular tag_yellow","circular turn_left","circular turn_right","circular user","circular warning","circular world","circular yes"],[[],[1],[2],[3],[4],[5],[6],[7],[8],[9],[10],[11],[12],[13],[14],[15],[16],[17],[18],[19],[20],[21],[22],[23],[24],[25],[26],[27],[28],[29],[30],[31],[32],[33],[34],[35],[36],[37],[38],[39],[40],[41],[42],[43],[44],[45],[46],[47],[48],[49],[50],[51],[52],[53],[54],[55],[56],[57],[58],[59],[60],[61],[62],[63],[64],[65],[66],[67],[68],[69],[70],[71],[72],[73],[74],[75],[76],[77],[78],[79],[80],[81],[82],[83],[84],[85],[86],[87],[88],[89],[90],[91],[92],[93],[94],[95],[96],[97],[98],[99],[100],[101],[102],[103],[104],[105],[106],[107],[108],[109],[110],[111],[112],[113],[114],[115],[116],[117]],[0],[0],[8,0],[16,0],[0],[0],[0],[8,0],[16,0],["0,0,16,16",""],["rect",""]],[[],[],[],[],[],[],[],[],[],[],[],[],[],[]]]]},"\/big\/":{"f":[],"w":[],"h":[],"i":[]},"sites\/all\/libraries\/getlocations\/markers\/big\/":{"f":["shadow.png","blue.png","red.png"],"w":[56,30],"h":[51],"i":[[[["defaults","big blue","big red"],["","Big Blue","Big Red"],[[],[1],[2]],[0],[0],[15,0],[51,0],[0],[0],[0],[15,0],[51,0],["0,0,30,51",""],["rect",""]],[[],[],[],[],[],[],[],[],[],[],[],[],[],[]]]]}};
;
/*jslint browser: true, confusion: true, sloppy: true, vars: true, nomen: false, plusplus: false, indent: 2 */
/*global window,google */

/**
 * @name MarkerClustererPlus for Google Maps V3
 * @version 2.0.15 [October 18, 2012]
 * @author Gary Little
 * @fileoverview
 * The library creates and manages per-zoom-level clusters for large amounts of markers.
 * <p>
 * This is an enhanced V3 implementation of the
 * <a href="http://gmaps-utility-library-dev.googlecode.com/svn/tags/markerclusterer/"
 * >V2 MarkerClusterer</a> by Xiaoxi Wu. It is based on the
 * <a href="http://google-maps-utility-library-v3.googlecode.com/svn/tags/markerclusterer/"
 * >V3 MarkerClusterer</a> port by Luke Mahe. MarkerClustererPlus was created by Gary Little.
 * <p>
 * v2.0 release: MarkerClustererPlus v2.0 is backward compatible with MarkerClusterer v1.0. It
 *  adds support for the <code>ignoreHidden</code>, <code>title</code>, <code>printable</code>,
 *  <code>batchSizeIE</code>, and <code>calculator</code> properties as well as support for
 *  four more events. It also allows greater control over the styling of the text that appears
 *  on the cluster marker. The documentation has been significantly improved and the overall
 *  code has been simplified and polished. Very large numbers of markers can now be managed
 *  without causing Javascript timeout errors on Internet Explorer. Note that the name of the
 *  <code>clusterclick</code> event has been deprecated. The new name is <code>click</code>,
 *  so please change your application code now.
 */

/**
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


/**
 * @name ClusterIconStyle
 * @class This class represents the object for values in the <code>styles</code> array passed
 *  to the {@link MarkerClusterer} constructor. The element in this array that is used to
 *  style the cluster icon is determined by calling the <code>calculator</code> function.
 *
 * @property {string} url The URL of the cluster icon image file. Required.
 * @property {number} height The height (in pixels) of the cluster icon. Required.
 * @property {number} width The width (in pixels) of the cluster icon. Required.
 * @property {Array} [anchor] The anchor position (in pixels) of the label text to be shown on
 *  the cluster icon, relative to the top left corner of the icon.
 *  The format is <code>[yoffset, xoffset]</code>. The <code>yoffset</code> must be positive
 *  and less than <code>height</code> and the <code>xoffset</code> must be positive and less
 *  than <code>width</code>. The default is to anchor the label text so that it is centered
 *  on the icon.
 * @property {Array} [anchorIcon] The anchor position (in pixels) of the cluster icon. This is the
 *  spot on the cluster icon that is to be aligned with the cluster position. The format is
 *  <code>[yoffset, xoffset]</code> where <code>yoffset</code> increases as you go down and
 *  <code>xoffset</code> increases to the right. The default anchor position is the center of the
 *  cluster icon.
 * @property {string} [textColor="black"] The color of the label text shown on the
 *  cluster icon.
 * @property {number} [textSize=11] The size (in pixels) of the label text shown on the
 *  cluster icon.
 * @property {number} [textDecoration="none"] The value of the CSS <code>text-decoration</code>
 *  property for the label text shown on the cluster icon.
 * @property {number} [fontWeight="bold"] The value of the CSS <code>font-weight</code>
 *  property for the label text shown on the cluster icon.
 * @property {number} [fontStyle="normal"] The value of the CSS <code>font-style</code>
 *  property for the label text shown on the cluster icon.
 * @property {number} [fontFamily="Arial,sans-serif"] The value of the CSS <code>font-family</code>
 *  property for the label text shown on the cluster icon.
 * @property {string} [backgroundPosition="0 0"] The position of the cluster icon image
 *  within the image defined by <code>url</code>. The format is <code>"xpos ypos"</code>
 *  (the same format as for the CSS <code>background-position</code> property). You must set
 *  this property appropriately when the image defined by <code>url</code> represents a sprite
 *  containing multiple images.
 */
/**
 * @name ClusterIconInfo
 * @class This class is an object containing general information about a cluster icon. This is
 *  the object that a <code>calculator</code> function returns.
 *
 * @property {string} text The text of the label to be shown on the cluster icon.
 * @property {number} index The index plus 1 of the element in the <code>styles</code>
 *  array to be used to style the cluster icon.
 * @property {string} title The tooltip to display when the mouse moves over the cluster icon.
 *  If this value is <code>undefined</code> or <code>""</code>, <code>title</code> is set to the
 *  value of the <code>title</code> property passed to the MarkerClusterer.
 */
/**
 * A cluster icon.
 *
 * @constructor
 * @extends google.maps.OverlayView
 * @param {Cluster} cluster The cluster with which the icon is to be associated.
 * @param {Array} [styles] An array of {@link ClusterIconStyle} defining the cluster icons
 *  to use for various cluster sizes.
 * @private
 */
function ClusterIcon(cluster, styles) {
  cluster.getMarkerClusterer().extend(ClusterIcon, google.maps.OverlayView);

  this.cluster_ = cluster;
  this.className_ = cluster.getMarkerClusterer().getClusterClass();
  this.styles_ = styles;
  this.center_ = null;
  this.div_ = null;
  this.sums_ = null;
  this.visible_ = false;

  this.setMap(cluster.getMap()); // Note: this causes onAdd to be called
}


/**
 * Adds the icon to the DOM.
 */
ClusterIcon.prototype.onAdd = function () {
  var cClusterIcon = this;
  var cMouseDownInCluster;
  var cDraggingMapByCluster;

  this.div_ = document.createElement("div");
  this.div_.className = this.className_;
  if (this.visible_) {
    this.show();
  }

  this.getPanes().overlayMouseTarget.appendChild(this.div_);

  // Fix for Issue 157
  google.maps.event.addListener(this.getMap(), "bounds_changed", function () {
    cDraggingMapByCluster = cMouseDownInCluster;
  });

  google.maps.event.addDomListener(this.div_, "mousedown", function () {
    cMouseDownInCluster = true;
    cDraggingMapByCluster = false;
  });

  google.maps.event.addDomListener(this.div_, "click", function (e) {
    cMouseDownInCluster = false;
    if (!cDraggingMapByCluster) {
      var theBounds;
      var mz;
      var mc = cClusterIcon.cluster_.getMarkerClusterer();
      /**
       * This event is fired when a cluster marker is clicked.
       * @name MarkerClusterer#click
       * @param {Cluster} c The cluster that was clicked.
       * @event
       */
      google.maps.event.trigger(mc, "click", cClusterIcon.cluster_);
      google.maps.event.trigger(mc, "clusterclick", cClusterIcon.cluster_); // deprecated name

      // The default click handler follows. Disable it by setting
      // the zoomOnClick property to false.
      if (mc.getZoomOnClick()) {
        // Zoom into the cluster.
        mz = mc.getMaxZoom();
        theBounds = cClusterIcon.cluster_.getBounds();
        mc.getMap().fitBounds(theBounds);
        // There is a fix for Issue 170 here:
        setTimeout(function () {
          mc.getMap().fitBounds(theBounds);
          // Don't zoom beyond the max zoom level
          if (mz !== null && (mc.getMap().getZoom() > mz)) {
            mc.getMap().setZoom(mz + 1);
          }
        }, 100);
      }

      // Prevent event propagation to the map:
      e.cancelBubble = true;
      if (e.stopPropagation) {
        e.stopPropagation();
      }
    }
  });

  google.maps.event.addDomListener(this.div_, "mouseover", function () {
    var mc = cClusterIcon.cluster_.getMarkerClusterer();
    /**
     * This event is fired when the mouse moves over a cluster marker.
     * @name MarkerClusterer#mouseover
     * @param {Cluster} c The cluster that the mouse moved over.
     * @event
     */
    google.maps.event.trigger(mc, "mouseover", cClusterIcon.cluster_);
  });

  google.maps.event.addDomListener(this.div_, "mouseout", function () {
    var mc = cClusterIcon.cluster_.getMarkerClusterer();
    /**
     * This event is fired when the mouse moves out of a cluster marker.
     * @name MarkerClusterer#mouseout
     * @param {Cluster} c The cluster that the mouse moved out of.
     * @event
     */
    google.maps.event.trigger(mc, "mouseout", cClusterIcon.cluster_);
  });
};


/**
 * Removes the icon from the DOM.
 */
ClusterIcon.prototype.onRemove = function () {
  if (this.div_ && this.div_.parentNode) {
    this.hide();
    google.maps.event.clearInstanceListeners(this.div_);
    this.div_.parentNode.removeChild(this.div_);
    this.div_ = null;
  }
};


/**
 * Draws the icon.
 */
ClusterIcon.prototype.draw = function () {
  if (this.visible_) {
    var pos = this.getPosFromLatLng_(this.center_);
    this.div_.style.top = pos.y + "px";
    this.div_.style.left = pos.x + "px";
  }
};


/**
 * Hides the icon.
 */
ClusterIcon.prototype.hide = function () {
  if (this.div_) {
    this.div_.style.display = "none";
  }
  this.visible_ = false;
};


/**
 * Positions and shows the icon.
 */
ClusterIcon.prototype.show = function () {
  if (this.div_) {
    var pos = this.getPosFromLatLng_(this.center_);
    this.div_.style.cssText = this.createCss(pos);
    if (this.cluster_.printable_) {
      // (Would like to use "width: inherit;" below, but doesn't work with MSIE)
      this.div_.innerHTML = "<img src='" + this.url_ + "'><div style='position: absolute; top: 0px; left: 0px; width: " + this.width_ + "px;'>" + this.sums_.text + "</div>";
    } else {
      this.div_.innerHTML = this.sums_.text;
    }
    if (typeof this.sums_.title === "undefined" || this.sums_.title === "") {
      this.div_.title = this.cluster_.getMarkerClusterer().getTitle();
    } else {
      this.div_.title = this.sums_.title;
    }
    this.div_.style.display = "";
  }
  this.visible_ = true;
};


/**
 * Sets the icon styles to the appropriate element in the styles array.
 *
 * @param {ClusterIconInfo} sums The icon label text and styles index.
 */
ClusterIcon.prototype.useStyle = function (sums) {
  this.sums_ = sums;
  var index = Math.max(0, sums.index - 1);
  index = Math.min(this.styles_.length - 1, index);
  var style = this.styles_[index];
  this.url_ = style.url;
  this.height_ = style.height;
  this.width_ = style.width;
  this.anchor_ = style.anchor;
  this.anchorIcon_ = style.anchorIcon || [parseInt(this.height_ / 2, 10), parseInt(this.width_ / 2, 10)];
  this.textColor_ = style.textColor || "black";
  this.textSize_ = style.textSize || 11;
  this.textDecoration_ = style.textDecoration || "none";
  this.fontWeight_ = style.fontWeight || "bold";
  this.fontStyle_ = style.fontStyle || "normal";
  this.fontFamily_ = style.fontFamily || "Arial,sans-serif";
  this.backgroundPosition_ = style.backgroundPosition || "0 0";
};


/**
 * Sets the position at which to center the icon.
 *
 * @param {google.maps.LatLng} center The latlng to set as the center.
 */
ClusterIcon.prototype.setCenter = function (center) {
  this.center_ = center;
};


/**
 * Creates the cssText style parameter based on the position of the icon.
 *
 * @param {google.maps.Point} pos The position of the icon.
 * @return {string} The CSS style text.
 */
ClusterIcon.prototype.createCss = function (pos) {
  var style = [];
  if (!this.cluster_.printable_) {
    style.push('background-image:url(' + this.url_ + ');');
    style.push('background-position:' + this.backgroundPosition_ + ';');
  }

  if (typeof this.anchor_ === 'object') {
    if (typeof this.anchor_[0] === 'number' && this.anchor_[0] > 0 &&
        this.anchor_[0] < this.height_) {
      style.push('height:' + (this.height_ - this.anchor_[0]) +
          'px; padding-top:' + this.anchor_[0] + 'px;');
    } else {
      style.push('height:' + this.height_ + 'px; line-height:' + this.height_ +
          'px;');
    }
    if (typeof this.anchor_[1] === 'number' && this.anchor_[1] > 0 &&
        this.anchor_[1] < this.width_) {
      style.push('width:' + (this.width_ - this.anchor_[1]) +
          'px; padding-left:' + this.anchor_[1] + 'px;');
    } else {
      style.push('width:' + this.width_ + 'px; text-align:center;');
    }
  } else {
    style.push('height:' + this.height_ + 'px; line-height:' +
        this.height_ + 'px; width:' + this.width_ + 'px; text-align:center;');
  }

  style.push('cursor:pointer; top:' + pos.y + 'px; left:' +
      pos.x + 'px; color:' + this.textColor_ + '; position:absolute; font-size:' +
      this.textSize_ + 'px; font-family:' + this.fontFamily_ + '; font-weight:' +
      this.fontWeight_ + '; font-style:' + this.fontStyle_ + '; text-decoration:' +
      this.textDecoration_ + ';');

  return style.join("");
};


/**
 * Returns the position at which to place the DIV depending on the latlng.
 *
 * @param {google.maps.LatLng} latlng The position in latlng.
 * @return {google.maps.Point} The position in pixels.
 */
ClusterIcon.prototype.getPosFromLatLng_ = function (latlng) {
  var pos = this.getProjection().fromLatLngToDivPixel(latlng);
  pos.x -= this.anchorIcon_[1];
  pos.y -= this.anchorIcon_[0];
  return pos;
};


/**
 * Creates a single cluster that manages a group of proximate markers.
 *  Used internally, do not call this constructor directly.
 * @constructor
 * @param {MarkerClusterer} mc The <code>MarkerClusterer</code> object with which this
 *  cluster is associated.
 */
function Cluster(mc) {
  this.markerClusterer_ = mc;
  this.map_ = mc.getMap();
  this.gridSize_ = mc.getGridSize();
  this.minClusterSize_ = mc.getMinimumClusterSize();
  this.averageCenter_ = mc.getAverageCenter();
  this.printable_ = mc.getPrintable();
  this.markers_ = [];
  this.center_ = null;
  this.bounds_ = null;
  this.clusterIcon_ = new ClusterIcon(this, mc.getStyles());
}


/**
 * Returns the number of markers managed by the cluster. You can call this from
 * a <code>click</code>, <code>mouseover</code>, or <code>mouseout</code> event handler
 * for the <code>MarkerClusterer</code> object.
 *
 * @return {number} The number of markers in the cluster.
 */
Cluster.prototype.getSize = function () {
  return this.markers_.length;
};


/**
 * Returns the array of markers managed by the cluster. You can call this from
 * a <code>click</code>, <code>mouseover</code>, or <code>mouseout</code> event handler
 * for the <code>MarkerClusterer</code> object.
 *
 * @return {Array} The array of markers in the cluster.
 */
Cluster.prototype.getMarkers = function () {
  return this.markers_;
};


/**
 * Returns the center of the cluster. You can call this from
 * a <code>click</code>, <code>mouseover</code>, or <code>mouseout</code> event handler
 * for the <code>MarkerClusterer</code> object.
 *
 * @return {google.maps.LatLng} The center of the cluster.
 */
Cluster.prototype.getCenter = function () {
  return this.center_;
};


/**
 * Returns the map with which the cluster is associated.
 *
 * @return {google.maps.Map} The map.
 * @ignore
 */
Cluster.prototype.getMap = function () {
  return this.map_;
};


/**
 * Returns the <code>MarkerClusterer</code> object with which the cluster is associated.
 *
 * @return {MarkerClusterer} The associated marker clusterer.
 * @ignore
 */
Cluster.prototype.getMarkerClusterer = function () {
  return this.markerClusterer_;
};


/**
 * Returns the bounds of the cluster.
 *
 * @return {google.maps.LatLngBounds} the cluster bounds.
 * @ignore
 */
Cluster.prototype.getBounds = function () {
  var i;
  var bounds = new google.maps.LatLngBounds(this.center_, this.center_);
  var markers = this.getMarkers();
  for (i = 0; i < markers.length; i++) {
    bounds.extend(markers[i].getPosition());
  }
  return bounds;
};


/**
 * Removes the cluster from the map.
 *
 * @ignore
 */
Cluster.prototype.remove = function () {
  this.clusterIcon_.setMap(null);
  this.markers_ = [];
  delete this.markers_;
};


/**
 * Adds a marker to the cluster.
 *
 * @param {google.maps.Marker} marker The marker to be added.
 * @return {boolean} True if the marker was added.
 * @ignore
 */
Cluster.prototype.addMarker = function (marker) {
  var i;
  var mCount;
  var mz;

  if (this.isMarkerAlreadyAdded_(marker)) {
    return false;
  }

  if (!this.center_) {
    this.center_ = marker.getPosition();
    this.calculateBounds_();
  } else {
    if (this.averageCenter_) {
      var l = this.markers_.length + 1;
      var lat = (this.center_.lat() * (l - 1) + marker.getPosition().lat()) / l;
      var lng = (this.center_.lng() * (l - 1) + marker.getPosition().lng()) / l;
      this.center_ = new google.maps.LatLng(lat, lng);
      this.calculateBounds_();
    }
  }

  marker.isAdded = true;
  this.markers_.push(marker);

  mCount = this.markers_.length;
  mz = this.markerClusterer_.getMaxZoom();
  if (mz !== null && this.map_.getZoom() > mz) {
    // Zoomed in past max zoom, so show the marker.
    if (marker.getMap() !== this.map_) {
      marker.setMap(this.map_);
    }
  } else if (mCount < this.minClusterSize_) {
    // Min cluster size not reached so show the marker.
    if (marker.getMap() !== this.map_) {
      marker.setMap(this.map_);
    }
  } else if (mCount === this.minClusterSize_) {
    // Hide the markers that were showing.
    for (i = 0; i < mCount; i++) {
      this.markers_[i].setMap(null);
    }
  } else {
    marker.setMap(null);
  }

  this.updateIcon_();
  return true;
};


/**
 * Determines if a marker lies within the cluster's bounds.
 *
 * @param {google.maps.Marker} marker The marker to check.
 * @return {boolean} True if the marker lies in the bounds.
 * @ignore
 */
Cluster.prototype.isMarkerInClusterBounds = function (marker) {
  return this.bounds_.contains(marker.getPosition());
};


/**
 * Calculates the extended bounds of the cluster with the grid.
 */
Cluster.prototype.calculateBounds_ = function () {
  var bounds = new google.maps.LatLngBounds(this.center_, this.center_);
  this.bounds_ = this.markerClusterer_.getExtendedBounds(bounds);
};


/**
 * Updates the cluster icon.
 */
Cluster.prototype.updateIcon_ = function () {
  var mCount = this.markers_.length;
  var mz = this.markerClusterer_.getMaxZoom();

  if (mz !== null && this.map_.getZoom() > mz) {
    this.clusterIcon_.hide();
    return;
  }

  if (mCount < this.minClusterSize_) {
    // Min cluster size not yet reached.
    this.clusterIcon_.hide();
    return;
  }

  var numStyles = this.markerClusterer_.getStyles().length;
  var sums = this.markerClusterer_.getCalculator()(this.markers_, numStyles);
  this.clusterIcon_.setCenter(this.center_);
  this.clusterIcon_.useStyle(sums);
  this.clusterIcon_.show();
};


/**
 * Determines if a marker has already been added to the cluster.
 *
 * @param {google.maps.Marker} marker The marker to check.
 * @return {boolean} True if the marker has already been added.
 */
Cluster.prototype.isMarkerAlreadyAdded_ = function (marker) {
  var i;
  if (this.markers_.indexOf) {
    return this.markers_.indexOf(marker) !== -1;
  } else {
    for (i = 0; i < this.markers_.length; i++) {
      if (marker === this.markers_[i]) {
        return true;
      }
    }
  }
  return false;
};


/**
 * @name MarkerClustererOptions
 * @class This class represents the optional parameter passed to
 *  the {@link MarkerClusterer} constructor.
 * @property {number} [gridSize=60] The grid size of a cluster in pixels. The grid is a square.
 * @property {number} [maxZoom=null] The maximum zoom level at which clustering is enabled or
 *  <code>null</code> if clustering is to be enabled at all zoom levels.
 * @property {boolean} [zoomOnClick=true] Whether to zoom the map when a cluster marker is
 *  clicked. You may want to set this to <code>false</code> if you have installed a handler
 *  for the <code>click</code> event and it deals with zooming on its own.
 * @property {boolean} [averageCenter=false] Whether the position of a cluster marker should be
 *  the average position of all markers in the cluster. If set to <code>false</code>, the
 *  cluster marker is positioned at the location of the first marker added to the cluster.
 * @property {number} [minimumClusterSize=2] The minimum number of markers needed in a cluster
 *  before the markers are hidden and a cluster marker appears.
 * @property {boolean} [ignoreHidden=false] Whether to ignore hidden markers in clusters. You
 *  may want to set this to <code>true</code> to ensure that hidden markers are not included
 *  in the marker count that appears on a cluster marker (this count is the value of the
 *  <code>text</code> property of the result returned by the default <code>calculator</code>).
 *  If set to <code>true</code> and you change the visibility of a marker being clustered, be
 *  sure to also call <code>MarkerClusterer.repaint()</code>.
 * @property {boolean} [printable=false] Whether to make the cluster icons printable. Do not
 *  set to <code>true</code> if the <code>url</code> fields in the <code>styles</code> array
 *  refer to image sprite files.
 * @property {string} [title=""] The tooltip to display when the mouse moves over a cluster
 *  marker. (Alternatively, you can use a custom <code>calculator</code> function to specify a
 *  different tooltip for each cluster marker.)
 * @property {function} [calculator=MarkerClusterer.CALCULATOR] The function used to determine
 *  the text to be displayed on a cluster marker and the index indicating which style to use
 *  for the cluster marker. The input parameters for the function are (1) the array of markers
 *  represented by a cluster marker and (2) the number of cluster icon styles. It returns a
 *  {@link ClusterIconInfo} object. The default <code>calculator</code> returns a
 *  <code>text</code> property which is the number of markers in the cluster and an
 *  <code>index</code> property which is one higher than the lowest integer such that
 *  <code>10^i</code> exceeds the number of markers in the cluster, or the size of the styles
 *  array, whichever is less. The <code>styles</code> array element used has an index of
 *  <code>index</code> minus 1. For example, the default <code>calculator</code> returns a
 *  <code>text</code> value of <code>"125"</code> and an <code>index</code> of <code>3</code>
 *  for a cluster icon representing 125 markers so the element used in the <code>styles</code>
 *  array is <code>2</code>. A <code>calculator</code> may also return a <code>title</code>
 *  property that contains the text of the tooltip to be used for the cluster marker. If
 *   <code>title</code> is not defined, the tooltip is set to the value of the <code>title</code>
 *   property for the MarkerClusterer.
 * @property {string} [clusterClass="cluster"] The name of the CSS class defining general styles
 *  for the cluster markers. Use this class to define CSS styles that are not set up by the code
 *  that processes the <code>styles</code> array.
 * @property {Array} [styles] An array of {@link ClusterIconStyle} elements defining the styles
 *  of the cluster markers to be used. The element to be used to style a given cluster marker
 *  is determined by the function defined by the <code>calculator</code> property.
 *  The default is an array of {@link ClusterIconStyle} elements whose properties are derived
 *  from the values for <code>imagePath</code>, <code>imageExtension</code>, and
 *  <code>imageSizes</code>.
 * @property {number} [batchSize=MarkerClusterer.BATCH_SIZE] Set this property to the
 *  number of markers to be processed in a single batch when using a browser other than
 *  Internet Explorer (for Internet Explorer, use the batchSizeIE property instead).
 * @property {number} [batchSizeIE=MarkerClusterer.BATCH_SIZE_IE] When Internet Explorer is
 *  being used, markers are processed in several batches with a small delay inserted between
 *  each batch in an attempt to avoid Javascript timeout errors. Set this property to the
 *  number of markers to be processed in a single batch; select as high a number as you can
 *  without causing a timeout error in the browser. This number might need to be as low as 100
 *  if 15,000 markers are being managed, for example.
 * @property {string} [imagePath=MarkerClusterer.IMAGE_PATH]
 *  The full URL of the root name of the group of image files to use for cluster icons.
 *  The complete file name is of the form <code>imagePath</code>n.<code>imageExtension</code>
 *  where n is the image file number (1, 2, etc.).
 * @property {string} [imageExtension=MarkerClusterer.IMAGE_EXTENSION]
 *  The extension name for the cluster icon image files (e.g., <code>"png"</code> or
 *  <code>"jpg"</code>).
 * @property {Array} [imageSizes=MarkerClusterer.IMAGE_SIZES]
 *  An array of numbers containing the widths of the group of
 *  <code>imagePath</code>n.<code>imageExtension</code> image files.
 *  (The images are assumed to be square.)
 */
/**
 * Creates a MarkerClusterer object with the options specified in {@link MarkerClustererOptions}.
 * @constructor
 * @extends google.maps.OverlayView
 * @param {google.maps.Map} map The Google map to attach to.
 * @param {Array.<google.maps.Marker>} [opt_markers] The markers to be added to the cluster.
 * @param {MarkerClustererOptions} [opt_options] The optional parameters.
 */
function MarkerClusterer(map, opt_markers, opt_options) {
  // MarkerClusterer implements google.maps.OverlayView interface. We use the
  // extend function to extend MarkerClusterer with google.maps.OverlayView
  // because it might not always be available when the code is defined so we
  // look for it at the last possible moment. If it doesn't exist now then
  // there is no point going ahead :)
  this.extend(MarkerClusterer, google.maps.OverlayView);

  opt_markers = opt_markers || [];
  opt_options = opt_options || {};

  this.markers_ = [];
  this.clusters_ = [];
  this.listeners_ = [];
  this.activeMap_ = null;
  this.ready_ = false;

  this.gridSize_ = opt_options.gridSize || 60;
  this.minClusterSize_ = opt_options.minimumClusterSize || 2;
  this.maxZoom_ = opt_options.maxZoom || null;
  this.styles_ = opt_options.styles || [];
  this.title_ = opt_options.title || "";
  this.zoomOnClick_ = true;
  if (opt_options.zoomOnClick !== undefined) {
    this.zoomOnClick_ = opt_options.zoomOnClick;
  }
  this.averageCenter_ = false;
  if (opt_options.averageCenter !== undefined) {
    this.averageCenter_ = opt_options.averageCenter;
  }
  this.ignoreHidden_ = false;
  if (opt_options.ignoreHidden !== undefined) {
    this.ignoreHidden_ = opt_options.ignoreHidden;
  }
  this.printable_ = false;
  if (opt_options.printable !== undefined) {
    this.printable_ = opt_options.printable;
  }
  this.imagePath_ = opt_options.imagePath || MarkerClusterer.IMAGE_PATH;
  this.imageExtension_ = opt_options.imageExtension || MarkerClusterer.IMAGE_EXTENSION;
  this.imageSizes_ = opt_options.imageSizes || MarkerClusterer.IMAGE_SIZES;
  this.calculator_ = opt_options.calculator || MarkerClusterer.CALCULATOR;
  this.batchSize_ = opt_options.batchSize || MarkerClusterer.BATCH_SIZE;
  this.batchSizeIE_ = opt_options.batchSizeIE || MarkerClusterer.BATCH_SIZE_IE;
  this.clusterClass_ = opt_options.clusterClass || "cluster";

  if (navigator.userAgent.toLowerCase().indexOf("msie") !== -1) {
    // Try to avoid IE timeout when processing a huge number of markers:
    this.batchSize_ = this.batchSizeIE_;
  }

  this.setupStyles_();

  this.addMarkers(opt_markers, true);
  this.setMap(map); // Note: this causes onAdd to be called
}


/**
 * Implementation of the onAdd interface method.
 * @ignore
 */
MarkerClusterer.prototype.onAdd = function () {
  var cMarkerClusterer = this;

  this.activeMap_ = this.getMap();
  this.ready_ = true;

  this.repaint();

  // Add the map event listeners
  this.listeners_ = [
    google.maps.event.addListener(this.getMap(), "zoom_changed", function () {
      cMarkerClusterer.resetViewport_(false);
      // Workaround for this Google bug: when map is at level 0 and "-" of
      // zoom slider is clicked, a "zoom_changed" event is fired even though
      // the map doesn't zoom out any further. In this situation, no "idle"
      // event is triggered so the cluster markers that have been removed
      // do not get redrawn. Same goes for a zoom in at maxZoom.
      if (this.getZoom() === (this.get("minZoom") || 0) || this.getZoom() === this.get("maxZoom")) {
        google.maps.event.trigger(this, "idle");
      }
    }),
    google.maps.event.addListener(this.getMap(), "idle", function () {
      cMarkerClusterer.redraw_();
    })
  ];
};


/**
 * Implementation of the onRemove interface method.
 * Removes map event listeners and all cluster icons from the DOM.
 * All managed markers are also put back on the map.
 * @ignore
 */
MarkerClusterer.prototype.onRemove = function () {
  var i;

  // Put all the managed markers back on the map:
  for (i = 0; i < this.markers_.length; i++) {
    if (this.markers_[i].getMap() !== this.activeMap_) {
      this.markers_[i].setMap(this.activeMap_);
    }
  }

  // Remove all clusters:
  for (i = 0; i < this.clusters_.length; i++) {
    this.clusters_[i].remove();
  }
  this.clusters_ = [];

  // Remove map event listeners:
  for (i = 0; i < this.listeners_.length; i++) {
    google.maps.event.removeListener(this.listeners_[i]);
  }
  this.listeners_ = [];

  this.activeMap_ = null;
  this.ready_ = false;
};


/**
 * Implementation of the draw interface method.
 * @ignore
 */
MarkerClusterer.prototype.draw = function () {};


/**
 * Sets up the styles object.
 */
MarkerClusterer.prototype.setupStyles_ = function () {
  var i, size;
  if (this.styles_.length > 0) {
    return;
  }

  for (i = 0; i < this.imageSizes_.length; i++) {
    size = this.imageSizes_[i];
    this.styles_.push({
      url: this.imagePath_ + (i + 1) + "." + this.imageExtension_,
      height: size,
      width: size
    });
  }
};


/**
 *  Fits the map to the bounds of the markers managed by the clusterer.
 */
MarkerClusterer.prototype.fitMapToMarkers = function () {
  var i;
  var markers = this.getMarkers();
  var bounds = new google.maps.LatLngBounds();
  for (i = 0; i < markers.length; i++) {
    bounds.extend(markers[i].getPosition());
  }

  this.getMap().fitBounds(bounds);
};


/**
 * Returns the value of the <code>gridSize</code> property.
 *
 * @return {number} The grid size.
 */
MarkerClusterer.prototype.getGridSize = function () {
  return this.gridSize_;
};


/**
 * Sets the value of the <code>gridSize</code> property.
 *
 * @param {number} gridSize The grid size.
 */
MarkerClusterer.prototype.setGridSize = function (gridSize) {
  this.gridSize_ = gridSize;
};


/**
 * Returns the value of the <code>minimumClusterSize</code> property.
 *
 * @return {number} The minimum cluster size.
 */
MarkerClusterer.prototype.getMinimumClusterSize = function () {
  return this.minClusterSize_;
};

/**
 * Sets the value of the <code>minimumClusterSize</code> property.
 *
 * @param {number} minimumClusterSize The minimum cluster size.
 */
MarkerClusterer.prototype.setMinimumClusterSize = function (minimumClusterSize) {
  this.minClusterSize_ = minimumClusterSize;
};


/**
 *  Returns the value of the <code>maxZoom</code> property.
 *
 *  @return {number} The maximum zoom level.
 */
MarkerClusterer.prototype.getMaxZoom = function () {
  return this.maxZoom_;
};


/**
 *  Sets the value of the <code>maxZoom</code> property.
 *
 *  @param {number} maxZoom The maximum zoom level.
 */
MarkerClusterer.prototype.setMaxZoom = function (maxZoom) {
  this.maxZoom_ = maxZoom;
};


/**
 *  Returns the value of the <code>styles</code> property.
 *
 *  @return {Array} The array of styles defining the cluster markers to be used.
 */
MarkerClusterer.prototype.getStyles = function () {
  return this.styles_;
};


/**
 *  Sets the value of the <code>styles</code> property.
 *
 *  @param {Array.<ClusterIconStyle>} styles The array of styles to use.
 */
MarkerClusterer.prototype.setStyles = function (styles) {
  this.styles_ = styles;
};


/**
 * Returns the value of the <code>title</code> property.
 *
 * @return {string} The content of the title text.
 */
MarkerClusterer.prototype.getTitle = function () {
  return this.title_;
};


/**
 *  Sets the value of the <code>title</code> property.
 *
 *  @param {string} title The value of the title property.
 */
MarkerClusterer.prototype.setTitle = function (title) {
  this.title_ = title;
};


/**
 * Returns the value of the <code>zoomOnClick</code> property.
 *
 * @return {boolean} True if zoomOnClick property is set.
 */
MarkerClusterer.prototype.getZoomOnClick = function () {
  return this.zoomOnClick_;
};


/**
 *  Sets the value of the <code>zoomOnClick</code> property.
 *
 *  @param {boolean} zoomOnClick The value of the zoomOnClick property.
 */
MarkerClusterer.prototype.setZoomOnClick = function (zoomOnClick) {
  this.zoomOnClick_ = zoomOnClick;
};


/**
 * Returns the value of the <code>averageCenter</code> property.
 *
 * @return {boolean} True if averageCenter property is set.
 */
MarkerClusterer.prototype.getAverageCenter = function () {
  return this.averageCenter_;
};


/**
 *  Sets the value of the <code>averageCenter</code> property.
 *
 *  @param {boolean} averageCenter The value of the averageCenter property.
 */
MarkerClusterer.prototype.setAverageCenter = function (averageCenter) {
  this.averageCenter_ = averageCenter;
};


/**
 * Returns the value of the <code>ignoreHidden</code> property.
 *
 * @return {boolean} True if ignoreHidden property is set.
 */
MarkerClusterer.prototype.getIgnoreHidden = function () {
  return this.ignoreHidden_;
};


/**
 *  Sets the value of the <code>ignoreHidden</code> property.
 *
 *  @param {boolean} ignoreHidden The value of the ignoreHidden property.
 */
MarkerClusterer.prototype.setIgnoreHidden = function (ignoreHidden) {
  this.ignoreHidden_ = ignoreHidden;
};


/**
 * Returns the value of the <code>imageExtension</code> property.
 *
 * @return {string} The value of the imageExtension property.
 */
MarkerClusterer.prototype.getImageExtension = function () {
  return this.imageExtension_;
};


/**
 *  Sets the value of the <code>imageExtension</code> property.
 *
 *  @param {string} imageExtension The value of the imageExtension property.
 */
MarkerClusterer.prototype.setImageExtension = function (imageExtension) {
  this.imageExtension_ = imageExtension;
};


/**
 * Returns the value of the <code>imagePath</code> property.
 *
 * @return {string} The value of the imagePath property.
 */
MarkerClusterer.prototype.getImagePath = function () {
  return this.imagePath_;
};


/**
 *  Sets the value of the <code>imagePath</code> property.
 *
 *  @param {string} imagePath The value of the imagePath property.
 */
MarkerClusterer.prototype.setImagePath = function (imagePath) {
  this.imagePath_ = imagePath;
};


/**
 * Returns the value of the <code>imageSizes</code> property.
 *
 * @return {Array} The value of the imageSizes property.
 */
MarkerClusterer.prototype.getImageSizes = function () {
  return this.imageSizes_;
};


/**
 *  Sets the value of the <code>imageSizes</code> property.
 *
 *  @param {Array} imageSizes The value of the imageSizes property.
 */
MarkerClusterer.prototype.setImageSizes = function (imageSizes) {
  this.imageSizes_ = imageSizes;
};


/**
 * Returns the value of the <code>calculator</code> property.
 *
 * @return {function} the value of the calculator property.
 */
MarkerClusterer.prototype.getCalculator = function () {
  return this.calculator_;
};


/**
 * Sets the value of the <code>calculator</code> property.
 *
 * @param {function(Array.<google.maps.Marker>, number)} calculator The value
 *  of the calculator property.
 */
MarkerClusterer.prototype.setCalculator = function (calculator) {
  this.calculator_ = calculator;
};


/**
 * Returns the value of the <code>printable</code> property.
 *
 * @return {boolean} the value of the printable property.
 */
MarkerClusterer.prototype.getPrintable = function () {
  return this.printable_;
};


/**
 * Sets the value of the <code>printable</code> property.
 *
 *  @param {boolean} printable The value of the printable property.
 */
MarkerClusterer.prototype.setPrintable = function (printable) {
  this.printable_ = printable;
};


/**
 * Returns the value of the <code>batchSizeIE</code> property.
 *
 * @return {number} the value of the batchSizeIE property.
 */
MarkerClusterer.prototype.getBatchSizeIE = function () {
  return this.batchSizeIE_;
};


/**
 * Sets the value of the <code>batchSizeIE</code> property.
 *
 *  @param {number} batchSizeIE The value of the batchSizeIE property.
 */
MarkerClusterer.prototype.setBatchSizeIE = function (batchSizeIE) {
  this.batchSizeIE_ = batchSizeIE;
};


/**
 * Returns the value of the <code>clusterClass</code> property.
 *
 * @return {string} the value of the clusterClass property.
 */
MarkerClusterer.prototype.getClusterClass = function () {
  return this.clusterClass_;
};


/**
 * Sets the value of the <code>clusterClass</code> property.
 *
 *  @param {string} clusterClass The value of the clusterClass property.
 */
MarkerClusterer.prototype.setClusterClass = function (clusterClass) {
  this.clusterClass_ = clusterClass;
};


/**
 *  Returns the array of markers managed by the clusterer.
 *
 *  @return {Array} The array of markers managed by the clusterer.
 */
MarkerClusterer.prototype.getMarkers = function () {
  return this.markers_;
};


/**
 *  Returns the number of markers managed by the clusterer.
 *
 *  @return {number} The number of markers.
 */
MarkerClusterer.prototype.getTotalMarkers = function () {
  return this.markers_.length;
};


/**
 * Returns the current array of clusters formed by the clusterer.
 *
 * @return {Array} The array of clusters formed by the clusterer.
 */
MarkerClusterer.prototype.getClusters = function () {
  return this.clusters_;
};


/**
 * Returns the number of clusters formed by the clusterer.
 *
 * @return {number} The number of clusters formed by the clusterer.
 */
MarkerClusterer.prototype.getTotalClusters = function () {
  return this.clusters_.length;
};


/**
 * Adds a marker to the clusterer. The clusters are redrawn unless
 *  <code>opt_nodraw</code> is set to <code>true</code>.
 *
 * @param {google.maps.Marker} marker The marker to add.
 * @param {boolean} [opt_nodraw] Set to <code>true</code> to prevent redrawing.
 */
MarkerClusterer.prototype.addMarker = function (marker, opt_nodraw) {
  this.pushMarkerTo_(marker);
  if (!opt_nodraw) {
    this.redraw_();
  }
};


/**
 * Adds an array of markers to the clusterer. The clusters are redrawn unless
 *  <code>opt_nodraw</code> is set to <code>true</code>.
 *
 * @param {Array.<google.maps.Marker>} markers The markers to add.
 * @param {boolean} [opt_nodraw] Set to <code>true</code> to prevent redrawing.
 */
MarkerClusterer.prototype.addMarkers = function (markers, opt_nodraw) {
  var i;
  for (i = 0; i < markers.length; i++) {
    this.pushMarkerTo_(markers[i]);
  }
  if (!opt_nodraw) {
    this.redraw_();
  }
};


/**
 * Pushes a marker to the clusterer.
 *
 * @param {google.maps.Marker} marker The marker to add.
 */
MarkerClusterer.prototype.pushMarkerTo_ = function (marker) {
  // If the marker is draggable add a listener so we can update the clusters on the dragend:
  if (marker.getDraggable()) {
    var cMarkerClusterer = this;
    google.maps.event.addListener(marker, "dragend", function () {
      if (cMarkerClusterer.ready_) {
        this.isAdded = false;
        cMarkerClusterer.repaint();
      }
    });
  }
  marker.isAdded = false;
  this.markers_.push(marker);
};


/**
 * Removes a marker from the cluster.  The clusters are redrawn unless
 *  <code>opt_nodraw</code> is set to <code>true</code>. Returns <code>true</code> if the
 *  marker was removed from the clusterer.
 *
 * @param {google.maps.Marker} marker The marker to remove.
 * @param {boolean} [opt_nodraw] Set to <code>true</code> to prevent redrawing.
 * @return {boolean} True if the marker was removed from the clusterer.
 */
MarkerClusterer.prototype.removeMarker = function (marker, opt_nodraw) {
  var removed = this.removeMarker_(marker);

  if (!opt_nodraw && removed) {
    this.repaint();
  }

  return removed;
};


/**
 * Removes an array of markers from the cluster. The clusters are redrawn unless
 *  <code>opt_nodraw</code> is set to <code>true</code>. Returns <code>true</code> if markers
 *  were removed from the clusterer.
 *
 * @param {Array.<google.maps.Marker>} markers The markers to remove.
 * @param {boolean} [opt_nodraw] Set to <code>true</code> to prevent redrawing.
 * @return {boolean} True if markers were removed from the clusterer.
 */
MarkerClusterer.prototype.removeMarkers = function (markers, opt_nodraw) {
  var i, r;
  var removed = false;

  for (i = 0; i < markers.length; i++) {
    r = this.removeMarker_(markers[i]);
    removed = removed || r;
  }

  if (!opt_nodraw && removed) {
    this.repaint();
  }

  return removed;
};


/**
 * Removes a marker and returns true if removed, false if not.
 *
 * @param {google.maps.Marker} marker The marker to remove
 * @return {boolean} Whether the marker was removed or not
 */
MarkerClusterer.prototype.removeMarker_ = function (marker) {
  var i;
  var index = -1;
  if (this.markers_.indexOf) {
    index = this.markers_.indexOf(marker);
  } else {
    for (i = 0; i < this.markers_.length; i++) {
      if (marker === this.markers_[i]) {
        index = i;
        break;
      }
    }
  }

  if (index === -1) {
    // Marker is not in our list of markers, so do nothing:
    return false;
  }

  marker.setMap(null);
  this.markers_.splice(index, 1); // Remove the marker from the list of managed markers
  return true;
};


/**
 * Removes all clusters and markers from the map and also removes all markers
 *  managed by the clusterer.
 */
MarkerClusterer.prototype.clearMarkers = function () {
  this.resetViewport_(true);
  this.markers_ = [];
};


/**
 * Recalculates and redraws all the marker clusters from scratch.
 *  Call this after changing any properties.
 */
MarkerClusterer.prototype.repaint = function () {
  var oldClusters = this.clusters_.slice();
  this.clusters_ = [];
  this.resetViewport_(false);
  this.redraw_();

  // Remove the old clusters.
  // Do it in a timeout to prevent blinking effect.
  setTimeout(function () {
    var i;
    for (i = 0; i < oldClusters.length; i++) {
      oldClusters[i].remove();
    }
  }, 0);
};


/**
 * Returns the current bounds extended by the grid size.
 *
 * @param {google.maps.LatLngBounds} bounds The bounds to extend.
 * @return {google.maps.LatLngBounds} The extended bounds.
 * @ignore
 */
MarkerClusterer.prototype.getExtendedBounds = function (bounds) {
  var projection = this.getProjection();

  // Turn the bounds into latlng.
  var tr = new google.maps.LatLng(bounds.getNorthEast().lat(),
      bounds.getNorthEast().lng());
  var bl = new google.maps.LatLng(bounds.getSouthWest().lat(),
      bounds.getSouthWest().lng());

  // Convert the points to pixels and the extend out by the grid size.
  var trPix = projection.fromLatLngToDivPixel(tr);
  trPix.x += this.gridSize_;
  trPix.y -= this.gridSize_;

  var blPix = projection.fromLatLngToDivPixel(bl);
  blPix.x -= this.gridSize_;
  blPix.y += this.gridSize_;

  // Convert the pixel points back to LatLng
  var ne = projection.fromDivPixelToLatLng(trPix);
  var sw = projection.fromDivPixelToLatLng(blPix);

  // Extend the bounds to contain the new bounds.
  bounds.extend(ne);
  bounds.extend(sw);

  return bounds;
};


/**
 * Redraws all the clusters.
 */
MarkerClusterer.prototype.redraw_ = function () {
  this.createClusters_(0);
};


/**
 * Removes all clusters from the map. The markers are also removed from the map
 *  if <code>opt_hide</code> is set to <code>true</code>.
 *
 * @param {boolean} [opt_hide] Set to <code>true</code> to also remove the markers
 *  from the map.
 */
MarkerClusterer.prototype.resetViewport_ = function (opt_hide) {
  var i, marker;
  // Remove all the clusters
  for (i = 0; i < this.clusters_.length; i++) {
    this.clusters_[i].remove();
  }
  this.clusters_ = [];

  // Reset the markers to not be added and to be removed from the map.
  for (i = 0; i < this.markers_.length; i++) {
    marker = this.markers_[i];
    marker.isAdded = false;
    if (opt_hide) {
      marker.setMap(null);
    }
  }
};


/**
 * Calculates the distance between two latlng locations in km.
 *
 * @param {google.maps.LatLng} p1 The first lat lng point.
 * @param {google.maps.LatLng} p2 The second lat lng point.
 * @return {number} The distance between the two points in km.
 * @see http://www.movable-type.co.uk/scripts/latlong.html
*/
MarkerClusterer.prototype.distanceBetweenPoints_ = function (p1, p2) {
  var R = 6371; // Radius of the Earth in km
  var dLat = (p2.lat() - p1.lat()) * Math.PI / 180;
  var dLon = (p2.lng() - p1.lng()) * Math.PI / 180;
  var a = Math.sin(dLat / 2) * Math.sin(dLat / 2) +
    Math.cos(p1.lat() * Math.PI / 180) * Math.cos(p2.lat() * Math.PI / 180) *
    Math.sin(dLon / 2) * Math.sin(dLon / 2);
  var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
  var d = R * c;
  return d;
};


/**
 * Determines if a marker is contained in a bounds.
 *
 * @param {google.maps.Marker} marker The marker to check.
 * @param {google.maps.LatLngBounds} bounds The bounds to check against.
 * @return {boolean} True if the marker is in the bounds.
 */
MarkerClusterer.prototype.isMarkerInBounds_ = function (marker, bounds) {
  return bounds.contains(marker.getPosition());
};


/**
 * Adds a marker to a cluster, or creates a new cluster.
 *
 * @param {google.maps.Marker} marker The marker to add.
 */
MarkerClusterer.prototype.addToClosestCluster_ = function (marker) {
  var i, d, cluster, center;
  var distance = 40000; // Some large number
  var clusterToAddTo = null;
  for (i = 0; i < this.clusters_.length; i++) {
    cluster = this.clusters_[i];
    center = cluster.getCenter();
    if (center) {
      d = this.distanceBetweenPoints_(center, marker.getPosition());
      if (d < distance) {
        distance = d;
        clusterToAddTo = cluster;
      }
    }
  }

  if (clusterToAddTo && clusterToAddTo.isMarkerInClusterBounds(marker)) {
    clusterToAddTo.addMarker(marker);
  } else {
    cluster = new Cluster(this);
    cluster.addMarker(marker);
    this.clusters_.push(cluster);
  }
};


/**
 * Creates the clusters. This is done in batches to avoid timeout errors
 *  in some browsers when there is a huge number of markers.
 *
 * @param {number} iFirst The index of the first marker in the batch of
 *  markers to be added to clusters.
 */
MarkerClusterer.prototype.createClusters_ = function (iFirst) {
  var i, marker;
  var mapBounds;
  var cMarkerClusterer = this;
  if (!this.ready_) {
    return;
  }

  // Cancel previous batch processing if we're working on the first batch:
  if (iFirst === 0) {
    /**
     * This event is fired when the <code>MarkerClusterer</code> begins
     *  clustering markers.
     * @name MarkerClusterer#clusteringbegin
     * @param {MarkerClusterer} mc The MarkerClusterer whose markers are being clustered.
     * @event
     */
    google.maps.event.trigger(this, "clusteringbegin", this);

    if (typeof this.timerRefStatic !== "undefined") {
      clearTimeout(this.timerRefStatic);
      delete this.timerRefStatic;
    }
  }

  // Get our current map view bounds.
  // Create a new bounds object so we don't affect the map.
  //
  // See Comments 9 & 11 on Issue 3651 relating to this workaround for a Google Maps bug:
  if (this.getMap().getZoom() > 3) {
    mapBounds = new google.maps.LatLngBounds(this.getMap().getBounds().getSouthWest(),
      this.getMap().getBounds().getNorthEast());
  } else {
    mapBounds = new google.maps.LatLngBounds(new google.maps.LatLng(85.02070771743472, -178.48388434375), new google.maps.LatLng(-85.08136444384544, 178.00048865625));
  }
  var bounds = this.getExtendedBounds(mapBounds);

  var iLast = Math.min(iFirst + this.batchSize_, this.markers_.length);

  for (i = iFirst; i < iLast; i++) {
    marker = this.markers_[i];
    if (!marker.isAdded && this.isMarkerInBounds_(marker, bounds)) {
      if (!this.ignoreHidden_ || (this.ignoreHidden_ && marker.getVisible())) {
        this.addToClosestCluster_(marker);
      }
    }
  }

  if (iLast < this.markers_.length) {
    this.timerRefStatic = setTimeout(function () {
      cMarkerClusterer.createClusters_(iLast);
    }, 0);
  } else {
    delete this.timerRefStatic;

    /**
     * This event is fired when the <code>MarkerClusterer</code> stops
     *  clustering markers.
     * @name MarkerClusterer#clusteringend
     * @param {MarkerClusterer} mc The MarkerClusterer whose markers are being clustered.
     * @event
     */
    google.maps.event.trigger(this, "clusteringend", this);
  }
};


/**
 * Extends an object's prototype by another's.
 *
 * @param {Object} obj1 The object to be extended.
 * @param {Object} obj2 The object to extend with.
 * @return {Object} The new extended object.
 * @ignore
 */
MarkerClusterer.prototype.extend = function (obj1, obj2) {
  return (function (object) {
    var property;
    for (property in object.prototype) {
      this.prototype[property] = object.prototype[property];
    }
    return this;
  }).apply(obj1, [obj2]);
};


/**
 * The default function for determining the label text and style
 * for a cluster icon.
 *
 * @param {Array.<google.maps.Marker>} markers The array of markers represented by the cluster.
 * @param {number} numStyles The number of marker styles available.
 * @return {ClusterIconInfo} The information resource for the cluster.
 * @constant
 * @ignore
 */
MarkerClusterer.CALCULATOR = function (markers, numStyles) {
  var index = 0;
  var title = "";
  var count = markers.length.toString();

  var dv = count;
  while (dv !== 0) {
    dv = parseInt(dv / 10, 10);
    index++;
  }

  index = Math.min(index, numStyles);
  return {
    text: count,
    index: index,
    title: title
  };
};


/**
 * The number of markers to process in one batch.
 *
 * @type {number}
 * @constant
 */
MarkerClusterer.BATCH_SIZE = 2000;


/**
 * The number of markers to process in one batch (IE only).
 *
 * @type {number}
 * @constant
 */
MarkerClusterer.BATCH_SIZE_IE = 500;


/**
 * The default root name for the marker cluster images.
 *
 * @type {string}
 * @constant
 */
MarkerClusterer.IMAGE_PATH = "http://google-maps-utility-library-v3.googlecode.com/svn/trunk/markerclustererplus/images/m";


/**
 * The default extension name for the marker cluster images.
 *
 * @type {string}
 * @constant
 */
MarkerClusterer.IMAGE_EXTENSION = "png";


/**
 * The default array of sizes for the marker cluster images.
 *
 * @type {Array.<number>}
 * @constant
 */
MarkerClusterer.IMAGE_SIZES = [53, 56, 66, 78, 90];
;
/**
 * @file
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations module for Drupal 7
 * this is for googlemaps API version 3
*/

// global vars
var getlocations_inputmap = [];
var getlocations_map = [];
var getlocations_markers = [];
var getlocations_settings = {};

(function ($) {

  function getlocations_init() {

    // in icons.js
    Drupal.getlocations.iconSetup();

    // each map has its own settings
    $.each(Drupal.settings.getlocations, function (key, settings) {

      // functions
      function FullScreenControl(fsd) {
        fsd.style.margin = "5px";
        fsd.style.boxShadow = "0 2px 4px rgba(0, 0, 0, 0.4)";
        fsdiv = document.createElement("DIV");
        fsdiv.style.height = "22px";
        fsdiv.style.backgroundColor = "white";
        fsdiv.style.borderColor = "#717B87";
        fsdiv.style.borderStyle = "solid";
        fsdiv.style.borderWidth = "1px";
        fsdiv.style.cursor = "pointer";
        fsdiv.style.textAlign = "center";
        fsdiv.title = Drupal.t('Full screen');
        fsdiv.innerHTML = '<img id="btnFullScreen" src="' + js_path + '/images/fs-map-full.png"/>';
        fsd.appendChild(fsdiv);
        google.maps.event.addDomListener(fsdiv, "click", function() {
          toggleFullScreen();
        });
      }

      function toggleFullScreen() {
        var cnt = getlocations_map[key].getCenter();
        $("#getlocations_map_wrapper_" + key).toggleClass("fullscreen");
        $("html,body").toggleClass("fullscreen-body");
        $(document).scrollTop(0);
        google.maps.event.trigger(getlocations_map[key], "resize");
        getlocations_map[key].setCenter(cnt);
        setTimeout( function() {
          if($("#getlocations_map_wrapper_" + key).hasClass("fullscreen")) {
            $("#btnFullScreen").attr("src", js_path + '/images/fs-map-normal.png');
            fsdiv.title = Drupal.t('Normal screen');
          }
          else {
            $("#btnFullScreen").attr("src", js_path + '/images/fs-map-full.png');
            fsdiv.title = Drupal.t('Full screen');
          }
        },200);
      }

      function doAllMarkers(map, gs, mkey) {

        var arr = gs.latlons;
        for (var i = 0; i < arr.length; i++) {
          arr2 = arr[i];
          if (arr2.length < 2) {
            return;
          }
          lat = arr2[0];
          lon = arr2[1];
          lid = arr2[2];
          name = arr2[3];
          mark = arr2[4];
          lidkey = arr2[5];
          customContent = arr2[6];
          cat = arr2[7];

          if (mark === '') {
            gs.markdone = gs.defaultIcon;
          }
          else {
            gs.markdone = Drupal.getlocations.getIcon(mark);
          }
          m = Drupal.getlocations.makeMarker(map, gs, lat, lon, lid, name, lidkey, customContent, cat, mkey);
          // still experimental
          getlocations_markers[mkey].lids[lid] = m;
          if (gs.usemarkermanager || gs.useclustermanager) {
            gs.batchr.push(m);
          }
        }
        // add batchr
        if (gs.usemarkermanager) {
         gs.mgr.addMarkers(gs.batchr, gs.minzoom, gs.maxzoom);
          gs.mgr.refresh();
        }
        else if (gs.useclustermanager) {
          gs.cmgr.addMarkers(gs.batchr, 0);
        }
      }

      function updateCopyrights() {
        if(getlocations_map[key].getMapTypeId() == "OSM") {
          copyrightNode.innerHTML = "OSM map data @<a target=\"_blank\" href=\"http://www.openstreetmap.org/\"> OpenStreetMap</a>-contributors,<a target=\"_blank\" href=\"http://creativecommons.org/licenses/by-sa/2.0/legalcode\"> CC BY-SA</a>";
        }
        else {
          copyrightNode.innerHTML = "";
        }
      }

      // end functions

      // is there really a map?
      if ( $("#getlocations_map_canvas_" + key).is('div') ) {

        // defaults
        global_settings = {
          maxzoom: 16,
          minzoom: 7,
          nodezoom: 12,
          minzoom_map: -1,
          maxzoom_map: -1,
          mgr: '',
          cmgr: '',
          cmgr_gridSize: null,
          cmgr_maxZoom: null,
          cmgr_minClusterSize: null,
          cmgr_styles: '',
          cmgr_style: null,
          defaultIcon: '',
          useInfoBubble: false,
          useInfoWindow: false,
          useCustomContent: false,
          useLink: false,
          markeraction: 0,
          markeractiontype: 1,
          show_maplinks: false,
          show_bubble_on_one_marker: false,
          infoBubbles: [],
          datanum: 0,
          batchr: []
        };

        var lat = parseFloat(settings.lat);
        var lng = parseFloat(settings.lng);
        var selzoom = parseInt(settings.zoom);
        var controltype = settings.controltype;
        var pancontrol = settings.pancontrol;
        var scale = settings.scale;
        var overview = settings.overview;
        var overview_opened = settings.overview_opened;
        var streetview_show = settings.streetview_show;
        var scrollw = settings.scrollwheel;
        var maptype = (settings.maptype ? settings.maptype : '');
        var baselayers = (settings.baselayers ? settings.baselayers : '');
        var map_marker = settings.map_marker;
        var poi_show = settings.poi_show;
        var transit_show = settings.transit_show;
        var pansetting = settings.pansetting;
        var draggable = settings.draggable;
        var map_styles = settings.styles;
        var map_backgroundcolor = settings.map_backgroundcolor;
        var fullscreen = (settings.fullscreen ? true : false);
        var js_path = settings.js_path;
        var useOpenStreetMap = false;
        var kml_url = settings.kml_url;
        var kml_url_click = (settings.kml_url_click ? true : false);
        var kml_url_infowindow = (settings.kml_url_infowindow ? true : false);
        var kml_url_viewport = (settings.kml_url_viewport ? true : false);

        global_settings.info_path = settings.info_path;
        global_settings.lidinfo_path = settings.lidinfo_path;
        global_settings.preload_data = settings.preload_data;
        if (settings.preload_data) {
          global_settings.getlocations_info = Drupal.settings.getlocations_info[key];
        }

        getlocations_markers[key] = {};
        getlocations_markers[key].coords = {};
        getlocations_markers[key].lids = {};
        getlocations_markers[key].cat = {};

        global_settings.locale_prefix = (settings.locale_prefix ? settings.locale_prefix + "/" : "");
        global_settings.show_bubble_on_one_marker = (settings.show_bubble_on_one_marker ? true : false);
        global_settings.minzoom = parseInt(settings.minzoom);
        global_settings.maxzoom = parseInt(settings.maxzoom);
        global_settings.nodezoom = parseInt(settings.nodezoom);

        if (settings.minzoom_map == -1) {
          global_settings.minzoom_map = null;
        }
        else {
          global_settings.minzoom_map = parseInt(settings.minzoom_map);
        }
        if (settings.maxzoom_map == -1) {
          global_settings.maxzoom_map = null;
        }
        else {
          global_settings.maxzoom_map = parseInt(settings.maxzoom_map);
        }

        global_settings.datanum = settings.datanum;
        global_settings.markermanagertype = settings.markermanagertype;
        global_settings.pansetting = settings.pansetting;
        // mobiles
        global_settings.is_mobile = settings.is_mobile;
        global_settings.show_maplinks = settings.show_maplinks;

        // prevent old msie from running markermanager
        var ver = Drupal.getlocations.msiedetect();
        var pushit = false;
        if ( (ver == '') || (ver && ver > 8)) {
          pushit = true;
        }

        if (pushit && settings.markermanagertype == 1 && settings.usemarkermanager) {
          global_settings.usemarkermanager = true;
          global_settings.useclustermanager = false;
        }
        else if (pushit && settings.markermanagertype == 2 && settings.useclustermanager == 1) {
          global_settings.cmgr_styles = Drupal.settings.getlocations_markerclusterer;
          global_settings.cmgr_style = (settings.markerclusterer_style == -1 ? null : settings.markerclusterer_style);
          global_settings.cmgr_gridSize = (settings.markerclusterer_size == -1 ? null : parseInt(settings.markerclusterer_size));
          global_settings.cmgr_maxZoom = (settings.markerclusterer_zoom == -1 ? null : parseInt(settings.markerclusterer_zoom));
          global_settings.cmgr_minClusterSize = (settings.markerclusterer_minsize == -1 ? null : parseInt(settings.markerclusterer_minsize));
          global_settings.cmgr_title = settings.markerclusterer_title;
          global_settings.useclustermanager = true;
          global_settings.usemarkermanager = false;
        }
        else {
          global_settings.usemarkermanager = false;
          global_settings.useclustermanager = false;
        }

        global_settings.markeraction = settings.markeraction;
        global_settings.markeractiontype = 'click';
        if (settings.markeractiontype == 2) {
          global_settings.markeractiontype = 'mouseover';
        }

        if (global_settings.markeraction == 1) {
          global_settings.useInfoWindow = true;
        }

        else if (global_settings.markeraction == 2) {
          global_settings.useInfoBubble = true;
        }
        else if (global_settings.markeraction == 3) {
          global_settings.useLink = true;
        }

        if((global_settings.useInfoWindow || global_settings.useInfoBubble) && settings.custom_content_enable == 1) {
          global_settings.useCustomContent = true;
        }
        global_settings.defaultIcon = Drupal.getlocations.getIcon(map_marker);

        // pipe delim
        global_settings.latlons = (settings.latlons ? settings.latlons : '');
        var minmaxes = (settings.minmaxes ? settings.minmaxes : '');
        var minlat = '';
        var minlon = '';
        var maxlat = '';
        var maxlon = '';
        var cenlat = '';
        var cenlon = '';

        if (minmaxes) {
          mmarr = minmaxes.split(',');
          minlat = parseFloat(mmarr[0]);
          minlon = parseFloat(mmarr[1]);
          maxlat = parseFloat(mmarr[2]);
          maxlon = parseFloat(mmarr[3]);
          cenlat = ((minlat + maxlat)/2);
          cenlon = ((minlon + maxlon)/2);
        }
        // menu type
        var mtc = false;
        if (settings.mtc == 'standard') { mtc = google.maps.MapTypeControlStyle.HORIZONTAL_BAR; }
        else if (settings.mtc == 'menu' ) { mtc = google.maps.MapTypeControlStyle.DROPDOWN_MENU; }

        // nav control type
        if (controltype == 'default') { controltype = google.maps.ZoomControlStyle.DEFAULT; }
        else if (controltype == 'small') { controltype = google.maps.ZoomControlStyle.SMALL; }
        else if (controltype == 'large') { controltype = google.maps.ZoomControlStyle.LARGE; }
        else { controltype = false; }

        // map type
        maptypes = [];
        if (maptype) {
          if (maptype == 'Map' && baselayers.Map) { maptype = google.maps.MapTypeId.ROADMAP; }
            if (maptype == 'Satellite' && baselayers.Satellite) { maptype = google.maps.MapTypeId.SATELLITE; }
            if (maptype == 'Hybrid' && baselayers.Hybrid) { maptype = google.maps.MapTypeId.HYBRID; }
            if (maptype == 'Physical' && baselayers.Physical) { maptype = google.maps.MapTypeId.TERRAIN; }
            if (baselayers.Map) { maptypes.push(google.maps.MapTypeId.ROADMAP); }
            if (baselayers.Satellite) { maptypes.push(google.maps.MapTypeId.SATELLITE); }
            if (baselayers.Hybrid) { maptypes.push(google.maps.MapTypeId.HYBRID); }
            if (baselayers.Physical) { maptypes.push(google.maps.MapTypeId.TERRAIN); }
            if (baselayers.OpenStreetMap) {
              maptypes.push("OSM");
              var copyrightNode = document.createElement('div');
              copyrightNode.id = 'copyright-control';
              copyrightNode.style.fontSize = '11px';
              copyrightNode.style.fontFamily = 'Arial, sans-serif';
              copyrightNode.style.margin = '0 2px 2px 0';
              copyrightNode.style.whiteSpace = 'nowrap';
              useOpenStreetMap = true;
            }
        }
        else {
          maptype = google.maps.MapTypeId.ROADMAP;
          maptypes.push(google.maps.MapTypeId.ROADMAP);
          maptypes.push(google.maps.MapTypeId.SATELLITE);
          maptypes.push(google.maps.MapTypeId.HYBRID);
          maptypes.push(google.maps.MapTypeId.TERRAIN);
        }
        // map styling
        var styles_array = [];
        if (map_styles) {
          try {
            styles_array = eval(map_styles);
          } catch (e) {
            if (e instanceof SyntaxError) {
              console.log(e.message);
              // Error on parsing string. Using default.
              styles_array = [];
            }
          }
        }

        // Merge styles with our settings.
        var styles = styles_array.concat([
          { featureType: "poi", elementType: "labels", stylers: [{ visibility: (poi_show ? 'on' : 'off') }] },
          { featureType: "transit", elementType: "labels", stylers: [{ visibility: (transit_show ? 'on' : 'off') }] }
        ]);

        var mapOpts = {
          zoom: selzoom,
          minZoom: global_settings.minzoom_map,
          maxZoom: global_settings.maxzoom_map,
          center: new google.maps.LatLng(lat, lng),
          mapTypeControl: (mtc ? true : false),
          mapTypeControlOptions: {style: mtc,  mapTypeIds: maptypes},
          zoomControl: (controltype ? true : false),
          zoomControlOptions: {style: controltype},
          panControl: (pancontrol ? true : false),
          mapTypeId: maptype,
          scrollwheel: (scrollw ? true : false),
          draggable: (draggable ? true : false),
          styles: styles,
          overviewMapControl: (overview ? true : false),
          overviewMapControlOptions: {opened: (overview_opened ? true : false)},
          streetViewControl: (streetview_show ? true : false),
          scaleControl: (scale ? true : false),
          scaleControlOptions: {style: google.maps.ScaleControlStyle.DEFAULT}
        };
        if (map_backgroundcolor) {
          mapOpts.backgroundColor = map_backgroundcolor;
        }

        getlocations_map[key] = new google.maps.Map(document.getElementById("getlocations_map_canvas_" + key), mapOpts);

        // OpenStreetMap
        if (useOpenStreetMap) {
          var tle = Drupal.t("OpenStreetMap");
          if (settings.mtc == 'menu') {
            tle = Drupal.t("OpenSMap");
          }
          getlocations_map[key].mapTypes.set("OSM", new google.maps.ImageMapType({
            getTileUrl: function(coord, zoom) {
              return "http://tile.openstreetmap.org/" + zoom + "/" + coord.x + "/" + coord.y + ".png";
            },
            tileSize: new google.maps.Size(256, 256),
            name: tle,
            maxZoom: 18
          }));
          google.maps.event.addListener(getlocations_map[key], 'maptypeid_changed', updateCopyrights);
          getlocations_map[key].controls[google.maps.ControlPosition.BOTTOM_RIGHT].push(copyrightNode);
        }

        // input map
        if (settings.inputmap) {
          getlocations_inputmap[key] = getlocations_map[key];
        }

        // set up markermanager
        if (global_settings.usemarkermanager) {
          global_settings.mgr = new MarkerManager(getlocations_map[key], {
            borderPadding: 50,
            maxZoom: global_settings.maxzoom,
            trackMarkers: false
          });
        }
        else if (global_settings.useclustermanager) {
          global_settings.cmgr = new MarkerClusterer(
            getlocations_map[key],
            [],
            {
              gridSize: global_settings.cmgr_gridSize,
              maxZoom: global_settings.cmgr_maxZoom,
              styles: global_settings.cmgr_styles[global_settings.cmgr_style],
              minimumClusterSize: global_settings.cmgr_minClusterSize,
              title: global_settings.cmgr_title
            }
          );
        }

        // KML
        if (kml_url) {
          var kmlLayer = {};
          var kmlLayertoggleState = [];
          kmlLayer[key] = new google.maps.KmlLayer({
            url: kml_url,
            preserveViewport: kml_url_viewport,
            clickable: kml_url_click,
            suppressInfoWindows: kml_url_infowindow
          });
          if (settings.kml_url_button_state > 0) {
            kmlLayer[key].setMap(getlocations_map[key]);
            kmlLayertoggleState[key] = true;
          }
          else {
            kmlLayer[key].setMap(null);
            kmlLayertoggleState[key] = false;
          }
          $("#getlocations_toggleKmlLayer_" + key).click( function() {
            l = (settings.kml_url_button_label ? settings.kml_url_button_label : Drupal.t('Kml Layer'));
            if (kmlLayertoggleState[key]) {
              kmlLayer[key].setMap(null);
              kmlLayertoggleState[key] = false;
              label = l + ' ' + Drupal.t('On');
            }
            else {
              kmlLayer[key].setMap(getlocations_map[key]);
              kmlLayertoggleState[key] = true;
              label = l + ' ' + Drupal.t('Off');
            }
            $(this).val(label);
          });
        }

        // Traffic Layer
        if (settings.trafficinfo) {
          var trafficInfo = {};
          var traffictoggleState = [];
          trafficInfo[key] = new google.maps.TrafficLayer();
          if (settings.trafficinfo_state > 0) {
            trafficInfo[key].setMap(getlocations_map[key]);
            traffictoggleState[key] = true;
          }
          else {
            trafficInfo[key].setMap(null);
            traffictoggleState[key] = false;
          }
          $("#getlocations_toggleTraffic_" + key).click( function() {
            if (traffictoggleState[key]) {
              trafficInfo[key].setMap(null);
              traffictoggleState[key] = false;
              label = Drupal.t('Traffic Info On');
            }
            else {
              trafficInfo[key].setMap(getlocations_map[key]);
              traffictoggleState[key] = true;
              label = Drupal.t('Traffic Info Off');
            }
            $(this).val(label);
          });
        }
        // Bicycling Layer
        if (settings.bicycleinfo) {
          var bicycleInfo = {};
          var bicycletoggleState =  [];
          bicycleInfo[key] = new google.maps.BicyclingLayer();
          if (settings.bicycleinfo_state > 0) {
            bicycleInfo[key].setMap(getlocations_map[key]);
            bicycletoggleState[key] = true;
          }
          else {
            bicycleInfo[key].setMap(null);
            bicycletoggleState[key] = false;
          }
          $("#getlocations_toggleBicycle_" + key).click( function() {
            if (bicycletoggleState[key]) {
              bicycleInfo[key].setMap(null);
              bicycletoggleState[key] = false;
              label = Drupal.t('Bicycle Info On');
            }
            else {
              bicycleInfo[key].setMap(getlocations_map[key]);
              bicycletoggleState[key] = true;
              label = Drupal.t('Bicycle Info Off');
            }
            $(this).val(label);
          });
        }
        // Transit Layer
        if (settings.transitinfo) {
          var transitInfo = {};
          var transittoggleState = [];
          transitInfo[key] = new google.maps.TransitLayer();
          if (settings.transitinfo_state > 0) {
            transitInfo[key].setMap(getlocations_map[key]);
            transittoggleState[key] = true;
          }
          else {
            transitInfo[key].setMap(null);
            transittoggleState[key] = false;
          }
          $("#getlocations_toggleTransit_" + key).click( function() {
            if (transittoggleState[key]) {
              transitInfo[key].setMap(null);
              transittoggleState[key] = false;
              label = Drupal.t('Transit Info On');
            }
            else {
              transitInfo[key].setMap(getlocations_map[key]);
              transittoggleState[key] = true;
              label = Drupal.t('Transit Info Off');
            }
            $(this).val(label);
          });
        }
        // Panoramio Layer
        if (settings.panoramio_use && settings.panoramio_show) {
          var panoramioLayer = {};
          var panoramiotoggleState = [];
          panoramioLayer[key] = new google.maps.panoramio.PanoramioLayer();
          if (settings.panoramio_state > 0) {
            panoramioLayer[key].setMap(getlocations_map[key]);
            panoramiotoggleState[key] = true;
          }
          else {
            panoramioLayer[key].setMap(null);
            panoramiotoggleState[key] = false;
          }
          $("#getlocations_togglePanoramio_" + key).click( function() {
            if (panoramiotoggleState[key]) {
              panoramioLayer[key].setMap(null);
              panoramiotoggleState[key] = false;
              label = Drupal.t('Panoramio On');
            }
            else {
              panoramioLayer[key].setMap(getlocations_map[key]);
              panoramiotoggleState[key] = true;
              label = Drupal.t('Panoramio Off');
            }
            $(this).val(label);
          });
        }
        // Weather Layer
        if (settings.weather_use && settings.weather_show) {
          var weatherLayer = {};
          var weathertoggleState = {};
          tu = google.maps.weather.TemperatureUnit.CELSIUS;
          if (settings.weather_temp == 2) {
            tu = google.maps.weather.TemperatureUnit.FAHRENHEIT;
          }
          sp = google.maps.weather.WindSpeedUnit.KILOMETERS_PER_HOUR;
          if (settings.weather_speed == 2) {
            sp = google.maps.weather.WindSpeedUnit.METERS_PER_SECOND;
          }
          else if (settings.weather_speed == 3) {
            sp = google.maps.weather.WindSpeedUnit.MILES_PER_HOUR;
          }
          var weatherOpts =  {
            temperatureUnits: tu,
            windSpeedUnits: sp,
            clickable: (settings.weather_clickable ? true : false),
            suppressInfoWindows: (settings.weather_info ? false : true)
          };
          if (settings.weather_label > 0) {
            weatherOpts.labelColor = google.maps.weather.LabelColor.BLACK;
            if (settings.weather_label == 2) {
              weatherOpts.labelColor = google.maps.weather.LabelColor.WHITE;
            }
          }
          weatherLayer[key] = new google.maps.weather.WeatherLayer(weatherOpts);
          if (settings.weather_state > 0) {
            weatherLayer[key].setMap(getlocations_map[key]);
            weathertoggleState[key] = true;
          }
          else {
            weatherLayer[key].setMap(null);
            weathertoggleState[key] = false;
          }
          // Cloud Layer
          if (settings.weather_cloud) {
            var cloudLayer = {};
            var cloudtoggleState = [];
            cloudLayer[key] = new google.maps.weather.CloudLayer();
            if (settings.weather_cloud_state > 0) {
              cloudLayer[key].setMap(getlocations_map[key]);
              cloudtoggleState[key] = true;
            }
            else {
              cloudLayer[key].setMap(null);
              cloudtoggleState[key] = false;
            }
            $("#getlocations_toggleCloud_" + key).click( function() {
              if (cloudtoggleState[key] == 1) {
                cloudLayer[key].setMap(null);
                cloudtoggleState[key] = false;
                label = Drupal.t('Clouds On');
              }
              else {
                cloudLayer[key].setMap(getlocations_map[key]);
                cloudtoggleState[key] = true;
                label = Drupal.t('Clouds Off');
              }
              $(this).val(label);
            });
          }
          $("#getlocations_toggleWeather_" + key).click( function() {
            if (weathertoggleState[key]) {
              weatherLayer[key].setMap(null);
              weathertoggleState[key] = false;
              label = Drupal.t('Weather On');
            }
            else {
              weatherLayer[key].setMap(getlocations_map[key]);
              weathertoggleState[key] = true;
              label = Drupal.t('Weather Off');
            }
            $(this).val(label);
          });
        }

        // exporting global_settings to getlocations_settings
        getlocations_settings[key] = global_settings;

        // markers and bounding
        if (! settings.inputmap && ! settings.searchmap) {
          //setTimeout(function() { doAllMarkers(getlocations_map[key], global_settings, key) }, 300);
          doAllMarkers(getlocations_map[key], global_settings, key);

          if (pansetting == 1) {
            Drupal.getlocations.doBounds(getlocations_map[key], minlat, minlon, maxlat, maxlon, true);
          }
          else if (pansetting == 2) {
            Drupal.getlocations.doBounds(getlocations_map[key], minlat, minlon, maxlat, maxlon, false);
          }
          else if (pansetting == 3) {
            if (cenlat  && cenlon) {
              c = new google.maps.LatLng(parseFloat(cenlat), parseFloat(cenlon));
              getlocations_map[key].setCenter(c);
            }
          }
        }

        // fullscreen
        if (fullscreen) {
          var fsdiv = '';
          $(document).keydown( function(kc) {
            var cd = (kc.keyCode ? kc.keyCode : kc.which);
            if(cd == 27){
              if($("body").hasClass("fullscreen-body")){
                toggleFullScreen();
              }
            }
          });

          var fsdoc = document.createElement("DIV");
          var fs = new FullScreenControl(fsdoc);
          fsdoc.index = 0;
          getlocations_map[key].controls[google.maps.ControlPosition.TOP_RIGHT].setAt(0, fsdoc);
        }

      }
    }); // end each setting loop
    $("body").addClass("getlocations-maps-processed");

  } // end getlocations_init

  Drupal.getlocations.makeMarker = function(map, gs, lat, lon, lid, title, lidkey, customContent, cat, mkey) {

    //if (! gs.markdone) {
    //  return;
    //}

    // categories
    if (cat) {
      getlocations_markers[mkey].cat[lid] = cat;
    }

    // check for duplicates
    var hash = lat + lon;
    hash = hash.replace(".","").replace(",", "").replace("-","");
    if (getlocations_markers[mkey].coords[hash] == null) {
      getlocations_markers[mkey].coords[hash] = 1;
    }
    else {
      // we have a duplicate
      // 10000 constrains the max, 0.0001 constrains the min distance
      m1 = (Math.random() /10000) + 0.0001;
      // randomise the operator
      m2 = Math.random();
      if (m2 > 0.5) {
        lat = parseFloat(lat) + m1;
      }
      else {
        lat = parseFloat(lat) - m1;
      }
      m1 = (Math.random() /10000) + 0.0001;
      m2 = Math.random();
      if (m2 > 0.5) {
        lon = parseFloat(lon) + m1;
      }
      else {
        lon = parseFloat(lon) - m1;
      }
    }

    // relocate function
    get_winlocation = function(gs, lid, lidkey) {
      if (gs.preload_data) {
        arr = gs.getlocations_info;
        for (var i = 0; i < arr.length; i++) {
          data = arr[i];
          if (lid == data.lid && lidkey == data.lidkey && data.content) {
            window.location = data.content;
          }
        }
      }
      else {
        // fetch link and relocate
        $.get(gs.lidinfo_path, {'lid': lid, 'key': lidkey}, function(data) {
          if (data.content) {
            window.location = data.content;
          }
        });
      }
    };

    var mouseoverTimeoutId = null;
    var mouseoverTimeout = (gs.markeractiontype == 'mouseover' ? 300 : 0);
    var p = new google.maps.LatLng(lat, lon);
    var m = new google.maps.Marker({
      icon: gs.markdone.image,
      shadow: gs.markdone.shadow,
      shape: gs.markdone.shape,
      map: map,
      position: p,
      title: title,
      optimized: false
    });

    if (gs.markeraction > 0) {
      google.maps.event.addListener(m, gs.markeractiontype, function() {
        mouseoverTimeoutId = setTimeout(function() {
          if (gs.useLink) {
            // relocate
            get_winlocation(gs, lid, lidkey);
          }
          else {
            if(gs.useCustomContent) {
              var cc = [];
              cc.content = customContent;
              Drupal.getlocations.showPopup(map, m, gs, cc);
            }
            else {
              // fetch bubble content
              if (gs.preload_data) {
                arr = gs.getlocations_info;
                for (var i = 0; i < arr.length; i++) {
                  data = arr[i];
                  if (lid == data.lid && lidkey == data.lidkey && data.content) {
                    Drupal.getlocations.showPopup(map, m, gs, data);
                  }
                }
              }
              else {
                var path = gs.info_path;
                var qs = {'lid': lid, 'key': lidkey};
                if (gs.show_distance) {
                  if ($("#getlocations_search_slat_" + mkey).is('div')) {
                    var slat = $("#getlocations_search_slat_" + mkey).html();
                    var slon = $("#getlocations_search_slon_" + mkey).html();
                    var sunit = $("#getlocations_search_sunit_" + mkey).html();
                    if (slat && slon) {
                      qs = {'lid': lid, 'key': lidkey, 'sdist': sunit + '|' + slat + '|' + slon};
                    }
                  }
                }

                $.get(path, qs, function(data) {
                  Drupal.getlocations.showPopup(map, m, gs, data);
                });
              }
            }
          }
        }, mouseoverTimeout);
      });
      google.maps.event.addListener(m,'mouseout', function() {
        if(mouseoverTimeoutId) {
          clearTimeout(mouseoverTimeoutId);
          mouseoverTimeoutId = null;
        }
      });

    }
    // we only have one marker
    if (gs.datanum == 1) {
      map.setCenter(p);
      map.setZoom(gs.nodezoom);
      // show_bubble_on_one_marker
      if (gs.show_bubble_on_one_marker && (gs.useInfoWindow || gs.useInfoBubble)) {
        google.maps.event.trigger(m, 'click');
      }
    }

    // show_maplinks
    if (gs.show_maplinks && (gs.useInfoWindow || gs.useInfoBubble || gs.useLink)) {
      // add link
      $("div#getlocations_map_links_" + mkey + " ul").append('<li><a href="#maptop_' + mkey + '" class="lid-' + lid + '">' + title + '</a></li>');
      // Add listener
      $("div#getlocations_map_links_" + mkey + " a.lid-" + lid).click(function(){
        $("div#getlocations_map_links_" + mkey + " a").removeClass('active');
        $("div#getlocations_map_links_" + mkey + " a.lid-" + lid).addClass('active');
        if (gs.useLink) {
          // relocate
          get_winlocation(gs, lid, lidkey);
        }
        else {
          // emulate
          google.maps.event.trigger(m, 'click');
        }
      });
    }

    return m;

  };

  Drupal.getlocations.showPopup = function(map, m, gs, data) {
    var ver = Drupal.getlocations.msiedetect();
    var pushit = false;
    if ( (ver == '') || (ver && ver > 8)) {
      pushit = true;
    }

    if (pushit) {
      // close any previous instances
      for (var i in gs.infoBubbles) {
        gs.infoBubbles[i].close();
      }
    }

    if (gs.useInfoBubble) {
      if (typeof(infoBubbleOptions) == 'object') {
        var infoBubbleOpts = infoBubbleOptions;
      }
      else {
        var infoBubbleOpts = {};
      }
      infoBubbleOpts.content = data.content;
      var infoBubble = new InfoBubble(infoBubbleOpts);
      infoBubble.open(map, m);
      if (pushit) {
        // add to the array
        gs.infoBubbles.push(infoBubble);
      }
    }
    else {
      if (typeof(infoWindowOptions) == 'object') {
        var infoWindowOpts = infoWindowOptions;
      }
      else {
        var infoWindowOpts = {};
      }
      infoWindowOpts.content = data.content;
      var infowindow = new google.maps.InfoWindow(infoWindowOpts);
      infowindow.open(map, m);
      if (pushit) {
        // add to the array
        gs.infoBubbles.push(infowindow);
      }
    }

  };

  Drupal.getlocations.doBounds = function(map, minlat, minlon, maxlat, maxlon, dopan) {
    if (minlat !== '' && minlon !== '' && maxlat !== '' && maxlon !== '') {
      // Bounding
      var minpoint = new google.maps.LatLng(parseFloat(minlat), parseFloat(minlon));
      var maxpoint = new google.maps.LatLng(parseFloat(maxlat), parseFloat(maxlon));
      var bounds = new google.maps.LatLngBounds(minpoint, maxpoint);
      if (dopan) {
        map.panToBounds(bounds);
      }
      else {
        map.fitBounds(bounds);
      }
    }
  };

  Drupal.getlocations.msiedetect = function() {
    var ieversion = '';
    if (/MSIE (\d+\.\d+);/.test(navigator.userAgent)){ //test for MSIE x.x;
     ieversion = new Number(RegExp.$1) // capture x.x portion and store as a number
    }
    return ieversion;
  };

  Drupal.getlocations.getGeoErrCode = function(errcode) {
    var errstr;
    if (errcode == google.maps.GeocoderStatus.ERROR) {
      errstr = Drupal.t("There was a problem contacting the Google servers.");
    }
    else if (errcode == google.maps.GeocoderStatus.INVALID_REQUEST) {
      errstr = Drupal.t("This GeocoderRequest was invalid.");
    }
    else if (errcode == google.maps.GeocoderStatus.OVER_QUERY_LIMIT) {
      errstr = Drupal.t("The webpage has gone over the requests limit in too short a period of time.");
    }
    else if (errcode == google.maps.GeocoderStatus.REQUEST_DENIED) {
      errstr = Drupal.t("The webpage is not allowed to use the geocoder.");
    }
    else if (errcode == google.maps.GeocoderStatus.UNKNOWN_ERROR) {
      errstr = Drupal.t("A geocoding request could not be processed due to a server error. The request may succeed if you try again.");
    }
    else if (errcode == google.maps.GeocoderStatus.ZERO_RESULTS) {
      errstr = Drupal.t("No result was found for this GeocoderRequest.");
    }
    return errstr;
  };

  Drupal.getlocations.geolocationErrorMessages = function(errcode) {
    var codes = [
      Drupal.t("due to an unknown error"),
      Drupal.t("because you didn't give me permission"),
      Drupal.t("because your browser couldn't determine your location"),
      Drupal.t("because it was taking too long to determine your location")];
    return codes[errcode];
  };

  // gogogo
  Drupal.behaviors.getlocations = {
    attach: function() {
      if (! $(".getlocations-maps-processed").is("body")) {
        getlocations_init();
      }
    }
  };

}(jQuery));
;
/**
 * @file
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Javascript functions for getlocations_fields module for Drupal 7
 * this is for googlemaps API version 3
 */

(function ($) {

  function getlocations_fields_init() {

    var gsettings = Drupal.settings.getlocations;
    var nodezoom = '';
    var mark = [];
    var map_marker = 'drupal';
    var adrsfield = 'getlocations_address_';
    var namefield = 'getlocations_name_';
    var streetfield = 'getlocations_street_';
    var additionalfield = 'getlocations_additional_';
    var cityfield = 'getlocations_city_';
    var provincefield = 'getlocations_province_';
    var postal_codefield = 'getlocations_postal_code_';
    var countryfield = 'getlocations_country_';
    var latfield = 'getlocations_latitude_';
    var lonfield = 'getlocations_longitude_';
    var point = [];
    var is_mobile = 0;
    var street_num_pos = 1;

    // each map has its own settings
    $.each(Drupal.settings.getlocations_fields, function (key, settings) {
      // is there really a map?
      if ($("#getlocations_map_canvas_" + key).is('div')) {

        var gset = gsettings[key];
        is_mobile = gset.is_mobile;
        var use_address = settings.use_address;
        var gkey = key;
        nodezoom = parseInt(settings.nodezoom);
        map_marker = settings.map_marker;
        var autocomplete_bias = settings.autocomplete_bias;
        var restrict_by_country = settings.restrict_by_country;
        var search_country = settings.search_country;
        var smart_ip_path = settings.smart_ip_path;
        street_num_pos = settings.street_num_pos;
        
	// Drefine a variable to limit the searches to the province field default value, if hidden or disabled (read only)
        provincefield_value_fixed = '';
        if ($("#" + provincefield + key).attr('disabled') || $("#" + provincefield + key).attr('hidden')) {
          provincefield_value_fixed = $("#" + provincefield + key).val();
        }


        // we need to see if this is an update
        lat = $("#" + latfield + key).val();
        lng = $("#" + lonfield + key).val();
        if (lat && lng) {
          point[key] = new google.maps.LatLng(parseFloat(lat), parseFloat(lng));
          updateMap(getlocations_inputmap[key], point[key], key);
        }

        if (! mark[key]) {
          // make an icon
          if (! point[key]) {
            point[key] = new google.maps.LatLng(parseFloat(gset.lat), parseFloat(gset.lng));
            getlocations_inputmap[key].setCenter(point[key]);
          }
          makeMoveMarker(getlocations_inputmap[key], point[key], key);
        }
        

        
        //console.log(use_address);
        
          var input_adrs = document.getElementById(adrsfield + key);
          var inputed_adrs;
          var place_adrs = {};
          place_adrs.inputed_adrs = ''; // Define an initial empty property for the address
        
        if (use_address > 0) {
	// If we you choose to use the google place autocomplete

          $("#" + 'getlocations_geocodebutton_' + key).click( function () {         
              
              $("#" + streetfield + key + " , " +
                "#" + additionalfield + key + " , " +
                "#" + cityfield + key + " , " +
                "#" + provincefield + key + " , " +
                "#" + postal_codefield + key + " , " +
                "#" + countryfield + key).unbind('change');
              
              manageGeobutton(key, use_address, place_adrs); // Try to Geocode and write the Marker on the map
              return false;
          });
          
          // If we change the content of the Find Address Field
          $('#' + adrsfield + key).change(function() {
            
            inputed_adrs = $(this).val();
                
                if ($.trim(inputed_adrs).length > 0) {
                    var inputed_adrs_arr = [];
                    
                    //alert($("#" + provincefield + key).attr('disabled') || $("#" + provincefield + key).attr('hidden'));
                    //alert($("#" + countryfield + key).attr('disabled') || $("#" + countryfield + key).attr('type') == 'hidden');
                    
                    if ($("#" + provincefield + key).attr('disabled') || $("#" + provincefield + key).attr('hidden')) {
                      var provincefield_value = $("#" + provincefield + key).val();
                      if (provincefield_value) {
                        inputed_adrs_arr.push(provincefield_value);
                      }
                    }
            
                     if ($("#" + countryfield + key).attr('disabled') || $("#" + countryfield + key).attr('type') == 'hidden') {                   
                      var countryfield_value = $("#" + countryfield + key).val();
                      if (countryfield_value) {
                        inputed_adrs_arr.push(countryfield_value);
                      }
                    }
                    
                    inputed_adrs = inputed_adrs + ' ' + inputed_adrs_arr.join(", ");
                }
            
            //alert(inputed_adrs);
            
            delete place_adrs.address_components; // We delete the previously saved address components
            place_adrs.formatted_address = inputed_adrs; // Set the place_adrs to the field value
            place_adrs.inputed_adrs = inputed_adrs; // Define the text inputed as a property for the place_adrs object
            //console.log(place_adrs);
            //console.log(inputed_adrs);
            //console.log(place_adrs.inputed_adrs);
            //console.log(place_adrs.formatted_address);
          });

          var fm_adrs = '';
          var opts = {};
          if (restrict_by_country > 0 && search_country) {
            var c = {'country':search_country};
            opts = {'componentRestrictions':c}
          }
          
	  // Does this work really ?
          opts.types = ['geocode'];
          
          var ac_adrs = new google.maps.places.Autocomplete(input_adrs, opts);

          if (autocomplete_bias) {
            ac_adrs.bindTo('bounds', getlocations_inputmap[key]);
          }
 
          google.maps.event.addListener(ac_adrs, 'place_changed', function () {
            place_adrs = ac_adrs.getPlace();
            inputed_adrs = place_adrs.formatted_address;
            place_adrs.inputed_adrs = inputed_adrs; //Reset the value of the imputed field to the Formatted Addrress fo the found Place
            //set_address_components(key, place_adrs.address_components); // We cannot Immediatly define the addres components, as it writes in the components smething that might not be acceptable in the context ... 

            if (use_address == 1) {
              // search box with geocode button
              //$("#" + 'getlocations_geocodebutton_' + key).click( function () {
              //
              //  $("#" + streetfield + key + " , " +
              //    "#" + additionalfield + key + " , " +
              //    "#" + cityfield + key + " , " +
              //    "#" + provincefield + key + " , " +
              //    "#" + postal_codefield + key + " , " +
              //    "#" + countryfield + key).unbind('change');
              //
              //  manageGeobutton(key, use_address, place_adrs);
              //  return false;
              //});
            }
            else {
              manageGeobutton(key, use_address, place_adrs);
            }        

          });
        }
        else {
          // no autocomplete
          $("#" + 'getlocations_geocodebutton_' + key).click( function () {
            manageGeobutton(key, use_address, place_adrs);
            return false;
          });
        }

        $("#" + 'getlocations_smart_ip_button_' + key).click( function () {
          manageSmartIpbutton(key, smart_ip_path);
          return false;
        });

        if (is_mobile) {
          if (navigator && navigator.geolocation) {
            $("#getlocations_geolocation_button_" + key + ":not(.getlocations-fields-geolocation-processed)").addClass("getlocations-fields-geolocation-processed").click( function () {
              manageGeolocationbutton(key);
              return false;
            });
          }
          else {
            $("#getlocations_geolocation_button_" + key).hide();
          }
        }

        // do 'fake' required fields
        var requireds = ['name', 'street', 'additional', 'city', 'province', 'postal_code', 'country'];
        $.each(requireds, function(k, v) {
          if ($(".getlocations_required_" + v + '_' + key).is("div")) {
            $("div.getlocations_required_" + v + "_" + key + " label").append(' <span class="form-required" title="' + Drupal.t("This field is required.") + '">*</span>');
          }
        });

        if (settings.latlon_warning > 0) {
          // warn on empty Latitude/Longitude
          $("input.form-submit#edit-submit").click( function () {
            if ($("#" + latfield + key).val() == '' && $("#" + lonfield + key).val() == '') {
              if (use_address > 0) {
                msg = Drupal.t('You must fill in the Latitude/Longitude fields. Use the Search or move the marker.');
              }
              else {
                 msg = Drupal.t('You must fill in the Latitude/Longitude fields. Use Geocoding or move the marker.');
              }
              alert(msg);
              return false;
            }
            return true;
          });
        }
      }
    }); // end each
    $("body").addClass("getlocations-fields-maps-processed");

    // functions

    function manageGeobutton(k, use_adrs, adrs) {
      
      console.log(adrs); // Italo ...
      
      var mmap = getlocations_inputmap[k];
      var kk = k;

	if (adrs.inputed_adrs == '' || $.trim(adrs.inputed_adrs).length == 0) {
        
        //alert('case1'); //Italo ...
        
        // pull the address out of the form
        var input_adrs_arr = [];
        
        var streetfield_value = $("#" + streetfield + k).val();
        if (streetfield_value) {
          input_adrs_arr.push(streetfield_value);
        }
        var additionalfield_value = $("#" + additionalfield + k).val();
        if (additionalfield_value) {
          input_adrs_arr.push(additionalfield_value);
        }
        var cityfield_value = $("#" + cityfield + k).val();
        if (cityfield_value) {
          input_adrs_arr.push(cityfield_value);
        }
        var provincefield_value = $("#" + provincefield + k).val();
        if (provincefield_value) {
          input_adrs_arr.push(provincefield_value);
        }
        var postal_codefield_value = $("#" + postal_codefield + k).val();
        if (postal_codefield_value) {
          input_adrs_arr.push(postal_codefield_value);
        }
        var countryfield_value = $("#" + countryfield + k).val();
        if (countryfield_value && streetfield_value) {
          if (countryfield_value == 'GB' ) {
            countryfield_value = 'UK';
          }
          input_adrs_arr.push(countryfield_value);
        }
        
        var input_adrstmp = input_adrs_arr.join(", ");
      }

      else if (!adrs.formatted_address || adrs.formatted_address != adrs.inputed_adrs) {
        //alert('case2');
        var input_adrstmp = adrs.inputed_adrs;
      }

      else {
        //alert('case3');
        var input_adrstmp = adrs.formatted_address;
      }
     
      //alert (input_adrstmp); // Italo ...
      
      if (input_adrstmp) {
        var input_adrs = {'address': input_adrstmp};
        // Create a Client Geocoder
        var geocoder = new google.maps.Geocoder();
        geocoder.geocode(input_adrs, function (results, status) {
          if (status == google.maps.GeocoderStatus.OK) {
            point[kk] = results[0].geometry.location;
            

            console.log (results[0]); // Italo ...
            //alert (typeof adrs.address_components == 'undefined');
            
            console.log($("#" + provincefield + k).val().toLowerCase());
	    
            if (results[0].address_components[2]) {
	      console.log(results[0].address_components[2].long_name.toLowerCase());
	      console.log(results[0].address_components[2].long_name.toLowerCase().indexOf(provincefield_value_fixed.toLowerCase()));
	    }
            
            if (provincefield_value_fixed) {
              if (results[0].address_components[2].long_name.toLowerCase().indexOf(provincefield_value_fixed.toLowerCase()) == -1 && 
                  results[0].address_components[3].long_name.toLowerCase().indexOf(provincefield_value_fixed.toLowerCase()) == -1 ) {
                var msg = Drupal.t('The asked address doesn\'t respect the Province of ' + provincefield_value_fixed);
                alert (msg);
                return;
              }
            }
            
            if (typeof adrs.address_components == 'undefined') { adrs.address_components = results[0].address_components; }
            
            console.log (adrs.address_components);
            
            lat = results[0].geometry.location.lat();
            lng = results[0].geometry.location.lng();
            $("#" + latfield + kk).val(lat);
            $("#" + lonfield + kk).val(lng);
            updateMap(mmap, point[kk], kk);
            
            if (use_adrs > 0) {
              set_address_components(kk, adrs.address_components);
            }
            
            if (!adrs.types) {
              // If the address is not a found Google Place
               $('#' + adrsfield + k).val(results[0].formatted_address);
               console.log('#' + adrsfield + k);
               console.log($('#' + adrsfield + k).val());
            }
            
          }
          else {
            var prm = {'!a': input_adrstmp, '!b': Drupal.getlocations.getGeoErrCode(status) };
            var msg = Drupal.t('Geocode for (!a) was not successful for the following reason: !b', prm);
            alert(msg);
          }
        });
      }
      else if ( ($("#" + latfield + k).val() !== '') && ($("#" + lonfield + k).val() !== '')  ) {
        // reverse geocoding
        lat = $("#" + latfield + k).val();
        lng = $("#" + lonfield + k).val();
        point[k] = new google.maps.LatLng(parseFloat(lat), parseFloat(lng));
        doReverseGeocode(point[k], k);
        updateMap(getlocations_inputmap[k], point[k], k);
      }
      else {
        var msg = Drupal.t('You have not entered an address.');
        alert(msg);
      }
    }

    // distribute the results to the various textfields
    function set_address_components(k, address_components) {
      streetfield_value = '';
      streetnumber_value = '';
      additionalfield_value = '';
      neighborhood_value = '';
      cityfield_value = '';
      provincefield_value = '';
      countryfield_value = '';
      postal_codefield_value = '';
      postal_code_prefix_field_value = '';
      admin_area_level_1 = '';
      admin_area_level_2 = '';
      admin_area_level_3 = '';
      for (var i = 0; i < address_components.length; i++) {
        type = address_components[i].types[0];
        //if (type == 'street_address') {
        //  streetfield_value = address_components[i].long_name;
        //}
        if (type == 'street_number') {
          streetnumber_value = address_components[i].long_name;
        }
        else if (type == 'route') {
          streetfield_value = address_components[i].long_name;
        }
        else if (type == 'locality') {
          cityfield_value = address_components[i].long_name;
        }
        else if (type == 'sublocality') {
          additionalfield_value = address_components[i].long_name;
        }
        else if (type == 'neighborhood') {
          neighborhood_value = address_components[i].long_name;
        }
        else if (type == 'administrative_area_level_3') {
          admin_area_level_3 = address_components[i].long_name;
        }
        else if (type == 'administrative_area_level_2') {
          admin_area_level_2 = address_components[i].long_name;
        }
        else if (type == 'administrative_area_level_1') {
          admin_area_level_1 = address_components[i].long_name;
        }
        else if (type == 'country') {
          countryfield_value = address_components[i].long_name;
        }
        else if (type == 'postal_code_prefix') {
          postal_code_prefix_field_value = address_components[i].long_name;
        }
        else if (type == 'postal_code') {
          postal_codefield_value = address_components[i].long_name;
        }
      }

      if (street_num_pos == 1) {
        $("#" + streetfield + k).val((streetnumber_value ? streetnumber_value + ' ' : '') + streetfield_value);
      }
      else {
        $("#" + streetfield + k).val(streetfield_value + (streetnumber_value ? ' ' + streetnumber_value : ''));
      }
      
      if ($.trim(provincefield_value_fixed.trim).length < 1 ) {
        if (admin_area_level_1) {
          provincefield_value = admin_area_level_1;
        }
        if (admin_area_level_1 && admin_area_level_2) {
          provincefield_value = admin_area_level_2 + ', ' + admin_area_level_1;
        }
        if (admin_area_level_1 && admin_area_level_2 && admin_area_level_3) {
          provincefield_value = admin_area_level_3 + ', ' + admin_area_level_2 + ', ' + admin_area_level_1;
        }
        if (admin_area_level_2 && admin_area_level_3) {
          provincefield_value = admin_area_level_3 + ', ' + admin_area_level_2;
        }
        if (admin_area_level_2 && ! provincefield_value) {
          provincefield_value = admin_area_level_2;
        }
        if (admin_area_level_3  && ! provincefield_value) {
          provincefield_value = admin_area_level_3;
        }
      } else {
        provincefield_value = provincefield_value_fixed;
      }

      $("#" + provincefield + k).val(provincefield_value);
      $("#" + additionalfield + k).val((additionalfield_value ? additionalfield_value : neighborhood_value));
      $("#" + cityfield + k).val(cityfield_value);
      if (postal_codefield_value) {
        $("#" + postal_codefield + k).val(postal_codefield_value);
      }
      else {
        $("#" + postal_codefield + k).val(postal_code_prefix_field_value);
      }

      // input or select box
      if ($("#" + countryfield + k).is("input")) {
        $("#" + countryfield + k).val(countryfield_value);
      }
      else if ($("#" + countryfield + k).is("select")) {
        $("#" + countryfield + k + " option").each( function(index) {
          if (countryfield_value == $(this).text()) {
            $("#" + countryfield + k).val($(this).val()).attr('selected', 'selected');
          }
          // fix 'The Netherlands' which is what google returns
          if (countryfield_value == 'The Netherlands') {
            $("#" + countryfield + k).val('NL').attr('selected', 'selected');
          }
        });
      }
      
        // Bind event to restore the Address Search Field when a component is edited (the user wants to refine the search on these components)
          $("#" + streetfield + k + " , " +
            "#" + additionalfield + k + " , " +
            "#" + cityfield + k + " , " +
            "#" + provincefield + k + " , " +
            "#" + postal_codefield + k + " , " +
            "#" + countryfield + k).bind('change', function () {
          
          //Set the Address Search Field Value to ''
          $('#' + adrsfield + k).val('').trigger('change');
          
        });
      
    } // set_address_components

    function makeMoveMarker(mmap, ppoint, mkey) {
      // remove existing marker
      if (mark[mkey]) {
        mark[mkey].setMap();
      }
      marker = Drupal.getlocations.getIcon(map_marker);
      mark[mkey] = new google.maps.Marker({
        icon: marker.image,
        shadow: marker.shadow,
        shape: marker.shape,
        map: mmap,
        position: ppoint,
        draggable: true,
        title: Drupal.t('Drag me to change position')
      });
      var mmmap = mmap;
      var mmkey = mkey;
      google.maps.event.addListener(mark[mkey], "dragend", function () {
        p = mark[mmkey].getPosition();
        mmmap.panTo(p);
        lat = p.lat();
        lng = p.lng();
        $("#" + latfield + mmkey).val(lat);
        $("#" + lonfield + mmkey).val(lng);
      });
      google.maps.event.addListener(mmap, "click", function (e) {
        p = e.latLng;
        mmmap.panTo(p);
        mark[mmkey].setPosition(p);
        lat = p.lat();
        lng = p.lng();
        $("#" + latfield + mmkey).val(lat);
        $("#" + lonfield + mmkey).val(lng);
      });
    }

    function updateMap(umap, pt, ukey) {
      umap.panTo(pt);
      umap.setZoom(nodezoom);
      makeMoveMarker(umap, pt, ukey);
    }

    function manageSmartIpbutton(k, p) {
      var kk = k;
      $.get(p, {}, function (loc) {
        if (loc) {
          lat = loc.latitude;
          lng = loc.longitude;
          if (lat && lng) {
            $("#" + latfield + kk).val(lat);
            $("#" + lonfield + kk).val(lng);
            if (loc.city) {
              $("#" + cityfield + kk).val(loc.city);
            }
            if (loc.region) {
              $("#" + provincefield + kk).val(loc.region);
            }
            if (loc.zip && loc.zip != '-') {
              $("#" + postal_codefield + kk).val(loc.zip);
            }

            if ($("#" + countryfield + kk).is("input")) {
              if (loc.country) {
                $("#" + countryfield + kk).val(loc.country);
              }
            }
            else if ($("#" + countryfield + kk).is("select")) {
              // do we already have countrycode?
              cc = '';
              if (loc.country_code) {
                if (loc.country_code == 'UK') {
                  cc = 'GB';
                }
                else {
                  cc = loc.country_code;
                }
              }
              if (cc) {
                $("#" + countryfield + kk).val(cc).attr('selected', 'selected');
              }
              else if (loc.country) {
                $("#" + countryfield + kk + " option").each( function(index) {
                  if (loc.country == $(this).text()) {
                    $("#" + countryfield + kk).val($(this).val()).attr('selected', 'selected');
                  }
                  // fix 'The Netherlands' which is what google returns
                  if (loc.country == 'The Netherlands') {
                    $("#" + countryfield + kk).val('NL').attr('selected', 'selected');
                  }
                });
              }
            }
            point[kk] = new google.maps.LatLng(parseFloat(lat), parseFloat(lng));
            updateMap(getlocations_inputmap[kk], point[kk], kk);
          }
        }
      });
    }

    // html5 geolocation
    function manageGeolocationbutton(k) {
      // html5
      var statusdiv = '#getlocations_geolocation_status_' + k;
      var statusmsg = '';
      $(statusdiv).html(statusmsg);
      navigator.geolocation.getCurrentPosition(
        function(position) {
          lat = position.coords.latitude;
          lng = position.coords.longitude;
          $("#" + latfield + k).val(lat);
          $("#" + lonfield + k).val(lng);
          point[k] = new google.maps.LatLng(parseFloat(lat), parseFloat(lng));
          updateMap(getlocations_inputmap[k], point[k], k);
          doReverseGeocode(point[k], k);
          //statusmsg = Drupal.t('Browser OK');
          //$(statusdiv).html(statusmsg);
        },
        function(error) {
          statusmsg = Drupal.t("Sorry, I couldn't find your location using the browser") + ' ' + Drupal.getlocations.geolocationErrorMessages(error.code) + ".";
          $(statusdiv).html(statusmsg);
        }, {maximumAge:10000}
      );
    }

    // reverse geocoding
    function doReverseGeocode(pt, k) {
      var kk = k;
      var input_ll = {'latLng': pt};
      // Create a Client Geocoder
      var geocoder = new google.maps.Geocoder();
      geocoder.geocode(input_ll, function (results, status) {
        if (status == google.maps.GeocoderStatus.OK) {
          if (results[0]) {
            if ($("#" + namefield + kk).val() == '') {
              $("#" + namefield + kk).val(results[0].formatted_address);
            }
            set_address_components(kk, results[0].address_components);
            $('#' + adrsfield + k).val(results[0].formatted_address);
          }
        }
        else {
          var prm = {'!b': Drupal.getlocations.getGeoErrCode(status) };
          var msg = Drupal.t('Geocode was not successful for the following reason: !b', prm);
          alert(msg);
        }
      });
    }
    

  } // end getlocations_fields_init

  Drupal.behaviors.getlocations_fields = {
    attach: function () {
      if (! $(".getlocations-fields-maps-processed").is("body")) {
        getlocations_fields_init();
      }
      // knock out the add more button, it wrecks all the maps
      $(".field-type-getlocations-fields input.field-add-more-submit").hide();
    }
  };
}(jQuery));
;
