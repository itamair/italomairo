/*
Copyright (c) 2003-2011, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

CKEDITOR.editorConfig = function( config )
{
	//alert ('ciao');
	// Define changes to default configuration here. For example:
	//config.language = 'it';
	//config.uiColor = '#AADC6E';
	config.filebrowserBrowseUrl = '/sites/all/modules/ckeditor 2/ckeditor/ckfinder/ckfinder.html';
    config.filebrowserImageBrowseUrl = '/sites/all/modules/ckeditor 2/ckeditor/ckfinder/ckfinder.html?Type=Images';
    config.filebrowserFlashBrowseUrl = '/sites/all/modules/ckeditor 2/ckeditor/ckfinder/ckfinder.html?Type=Flash';
    config.filebrowserUploadUrl = '/sites/all/modules/ckeditor 2/ckeditor/ckfinder/ckfinder/core/connector/php/connector.php?command=QuickUpload&type=Files';
    config.filebrowserImageUploadUrl = '/sites/all/modules/ckeditor 2/ckeditor/ckfinder/core/connector/php/connector.php?command=QuickUpload&type=Images';
    config.filebrowserFlashUploadUrl = '/sites/all/modules/ckeditor 2/ckeditor/ckfinder/core/connector/php/connector.php?command=QuickUpload&type=Flash';
};
