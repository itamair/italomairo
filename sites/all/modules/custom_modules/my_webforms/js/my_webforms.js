jQuery(document).ready(function() {
   
   controllaErrori();
   impostaViewRagSoc();
	jQuery('#edit-submitted-dati-personali-tipo-di-sottoscrizione-select').change(function() {
	 impostaViewRagSoc();
	});
	
        
      /****** Codice per aggiornare il markup delle newsletter associate alla Richiesta di Copia Gratuita ******/
      var markupNewsletter = jQuery('#webform-component-richiesta--subscribe-newsletter-correlate').html();
        
      jQuery('#edit-submitted-richiesta-rivista .form-radio').click(function() {
      jQuery('#webform-component-richiesta--subscribe-newsletter-correlate').html(markupNewsletter) ;
      settaNewslettAssociate(jQuery(this).attr('id'));
	});
      
      var selectOptions = jQuery('#edit-submitted-richiesta-rivista .form-item');
      //Se è presente l'unica opzione per un arivista allora viene subito scritto l'eleco delel newslette associate
      if (selectOptions.length == 1) settaNewslettAssociate('edit-submitted-richiesta-rivista-1');
	
     
      inserisciNegazione();




 jQuery('#normativa_privacy').click(function() {loadPrivacy();});
	//drupal_add_js('jQuery(document).ready(function () { jQuery( "#popup" ).dialog(); });', 'inline');
});

function controllaErrori(){
	jQuery('.messages.error.messages-inline').each(function(index) {
	   var rifer= jQuery(this).attr('rif');
	   if(jQuery("#"+rifer).attr('class')!="form-radios")
		jQuery(this).before(jQuery("#"+rifer));
	});
}

function impostaViewRagSoc(){
	var valDDL= jQuery('#edit-submitted-dati-personali-tipo-di-sottoscrizione-select').val();
	if(valDDL=='Privato' || !valDDL){
		
		jQuery('#edit-submitted-dati-personali-azienda-ente').val('-');
		jQuery('#webform-component-dati-personali--azienda-ente').slideUp();
	}
	else{  //alert (jQuery('#edit-submitted-dati-personali-azienda-ente').val());
		if (jQuery('#edit-submitted-dati-personali-azienda-ente').val() == '-') jQuery('#edit-submitted-dati-personali-azienda-ente').val('');
		jQuery('#webform-component-dati-personali--azienda-ente').slideDown();
	}
}
function inserisciNegazione(){
	var testo =jQuery(".submissionexixt").html();
//	if(testo != ''){
	if(testo){
		var descrizione='<span class="messages error">'+testo + '</span><br/><br/>';
		jQuery('#webform-component-richiesta').append(descrizione);
	}
}

function settaNewslettAssociate(idpassed){
var testo = "<strong>: "+jQuery('[for="'+idpassed+'"] .newsletters.hidden').text() + "</strong>";
jQuery('#webform-component-richiesta--subscribe-newsletter-correlate').append(testo);
}
 function loadPrivacy(){
		
	jQuery.ajax({
		data: {ln:jQuery( "#page-wrapper" ).attr('lan')},
		url: '/admin/getmyprivacy',
		//dataType:'json',
		//cache: false,
		global: false,
         dataType: 'html',
		contentType: "application/json",
		beforeSend:function(  ) {		
					/*var load="<div id=\"contloading\" style=\"text-align:center;height:150px;\"><img style=\"padding-top:50px;\" src=\"/themes/fieramilano/img/loading36.gif\"></div>";
					rewriteview(load);*/
				},
		success: function( data ) {		
					jQuery('#webform-component-termini-e-condizioni').append('<div id="popup" title="Privacy">'+data+'</div>');
					jQuery( "#popup" ).dialog({ width: 600 , height: (jQuery(window).height()/2) , modal: true});
										
				},
		error:function(xhr, status, errorThrown) {
             //   alert(errorThrown+'\n'+status+'\n'+xhr.statusText);
        }
		});
	return false;
 
 }