<div class="content-img">
        	<ul class="content-img-list">
        		<!-- <li class="content-img-list-item"><img src="https://www.baidu.com/img/bd_logo1.png" alt=""><a class="delete-btn"><i class="ico-delete"></i></a></li> -->
        	</ul>
        	<div class="file">
        		<i class="ico-plus"></i>上传图片，支持jpg/png<input type="file" name="file" accept="image/*" id="upload" >
        	</div>	
        </div>
        var fileList = this.files;
		for(var i = 0; i < fileList.length; i++) {
			var imgSrcI = getObjectURL(fileList[i]);
			imgName.push(fileList[i].name);
			imgSrc.push(imgSrcI);
			imgFile.push(fileList[i]);
		}
function getObjectURL(file) {
	var url = null ;
	if (window.createObjectURL!=undefined) { // basic
		url = window.createObjectURL(file) ;
	} else if (window.URL!=undefined) { // mozilla(firefox)
		url = window.URL.createObjectURL(file) ;
	} else if (window.webkitURL!=undefined) { // webkit or chrome
		url = window.webkitURL.createObjectURL(file) ;
	}
	return url ;
}
$('#upload').on('change',function(){		
		  if(imgSrc.length==4){
			return alert("最多只能上传4张图片");
		}
		var imgSize = this.files[0].size;  //b
		if(imgSize>1024*1024*1){//1M
			return alert("上传图片不能超过1M");
		}
		if(this.files[0].type != 'image/png' && this.files[0].type != 'image/jpeg' && this.files[0].type != 'image/gif'){
			return alert("图片上传格式不正确");
		}
	})
function addNewContent(obj) {
	$(obj).html("");
	for(var a = 0; a < imgSrc.length; a++) {
		var oldBox = $(obj).html();
		$(obj).html(oldBox + '<li class="content-img-list-item"><img src="'+imgSrc[a]+'" alt=""><a index="'+a+'" class="hide delete-btn"><i class="ico-delete"></i></a></li>');
	}
}
$('.content-img-list').on('mouseover','.content-img-list-item',function(){
		$(this).children('a').removeClass('hide');
	});
$('.content-img-list').on('mouseleave','.content-img-list-item',function(){
		$(this).children('a').addClass('hide');
	});
$(".content-img-list").on("click",'.content-img-list-item a',function(){
	    	var index = $(this).attr("index");
			imgSrc.splice(index, 1);
			imgFile.splice(index, 1);
			imgName.splice(index, 1);
			var boxId = ".content-img-list";
			addNewContent(boxId);
			if(imgSrc.length<4){//显示上传按钮
				$('.content-img .file').show();
			}
	  });
var formFile = new FormData();
$.each(imgFile, function(i, file){
            formFile.append('myFile[]', file);
        });
