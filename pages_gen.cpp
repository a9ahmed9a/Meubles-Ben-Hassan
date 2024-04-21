#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to generate HTML content
string generateHTML(const string& imageName, const string& productName, const string& productPrice, const string& productDescription) {
    string htmlContent = R"(
<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <meta name="author" content="Ichhari Media">
  <link rel="shortcut icon" href="favicon.png?v2">

  <meta name="description" content="" />

	<!-- Bootstrap CSS -->
	<link href="css/bootstrap.min.css" rel="stylesheet">
	<link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css" rel="stylesheet">
	<link href="css/tiny-slider.css" rel="stylesheet">
	<link href="css/style.css?v=1.8" rel="stylesheet">
	<title>)" + productName + R"( Ichhari-Ecom</title>
</head>
<body>
    <!-- Start Header/Navigation -->
    <nav class="custom-navbar navbar navbar navbar-expand-md navbar-dark bg-dark" arial-label="Furni navigation bar">

        <div class="container">
            <a class="navbar-brand" href="index.html">Ichhari-Ecom<span>.</span></a>

            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarsFurni" aria-controls="navbarsFurni" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            
            <div class="collapse navbar-collapse" id="navbarsFurni">
                <ul class="custom-navbar-nav navbar-nav ms-auto me-auto mb-2 mb-md-0">
                    <li class="nav-item">
                        <a class="nav-link" href="index.html">Home</a>
                    </li>
                    <li><a class="nav-link" href="shop.html">Shop</a></li>
                    <li><a class="nav-link" href="contact.html">Contact us</a></li>
                </ul>
            </div>
        </div>
            
        <div class="row d-lg-block d-none me-auto">
            <div class="">
                <div class="subscription-form">
                    <ul class="list-unstyled custom-social">
                        <li><a href="#"><span class="fa fa-brands fa-facebook-f"></span></a></li>
                        <li><a href="#"><span class="fa fa-brands fa-instagram"></span></a></li>
                        <li><a href="#"><span class="fa fa-brands fa-linkedin"></span></a></li>
                    </ul>
                </div>
            </div>
        </div>

    </nav>
    <!-- End Header/Navigation -->

    <div class="free-shipping d-flex align-items-center justify-content-center">
        <img src="icons/truck-svgrepo-com.svg" alt="">
        <p>FREE shiping</p>
    </div>

	<div class="container">
        <!-- single product -->
        <div class="single-product mt-5 ">
            <div class="container">
                <div class="row align-items-center">
                    <div class="col-md-5">
                        <div class="single-product-img">
                            <img src="images/)" + imageName + R"(" alt=")" + productName + R"(" class="img-fluid">
                        </div>
                    </div>

                    <div class="col-md-7 mt-4">
                        <div class="single-product-content">
                            <h3>)" + productName + R"(</h3>
                            <p>)" + productDescription + R"(</p>
                        </div>
                    </div>

                    <div class="col-md-12 mt-4 single-product-form">
                        <form action="command.php" methode="post" class="ms-3">
                            <div class="row align-items-center justify-content-center">
                                <div class="col-lg-5 p-0">
                                    <input type="text" id="Prodname" hidden value=")" + productName + R"(" class="w-100">
                                    <div class="">
                                        <div class="d-flex">
                                            <div class="w-10 icon d-flex align-items-center">
                                                <img src="icons/person-button-svgrepo-com.svg" alt="">
                                            </div>
                                            <input type="text" id="name" placeholder="Nom | الإسم الكامل" class="w-100">
                                        </div>
                                    </div>     
                                    <div class="">
                                        <div class="d-flex">
                                            <div class="w-10 icon d-flex align-items-center">
                                                <img src="icons/telephone-round-svgrepo-com.svg" alt="">
                                            </div>
                                            <input type="text" placeholder="Téléphone | رقم الهاتف" id="tele" class="w-100">
                                        </div>
                                    </div>     
                                    <div class="">
                                        <div class="d-flex">
                                            <div class="w-10 icon d-flex align-items-center">
                                                <img src="icons/map-point-wave-svgrepo-com.svg" alt="">
                                            </div>
                                            <input type="text" placeholder="Ville | المدينة" id="adrss" class="w-100">
                                        </div>
                                    </div>     
                                </div>  
                                <div class="col-lg-1"></div>       
                                <div class="col-lg-6 p-0 radio-form">
                                    <input type="radio" id="image1" hidden name="image" selected value="image1" checked>
                                    <label for="image1" class="d-flex w-auto"> 
                                        <img src="images/)" + imageName + R"(" alt="Image 1">
                                        <div class="radio-form-text d-flex align-items-center w-100">
                                            <p class="w-auto">1 camera</p>
                                            <p class="price text-end">1000dh</p>
                                        </div> 
                                    </label>
                
                                    <input type="radio" id="image2" hidden name="image" value="image1">
                                    <label for="image2" class="d-flex w-auto">
                                        <img src="images/)" + imageName + R"(" alt="Image 1">
                                        <div class="radio-form-text d-flex align-items-center w-100">
                                            <p class="w-auto">2 camera</p>
                                            <div class="price text-end">
                                                <p class="w-100 price text-end"><del>20000dh</del></p>
                                                <p class="w-100 price text-end">18000dh</p>
                                            </div>
                                        </div> 
                                    </label>

                                    <input type="radio" id="image3" hidden name="image" value="image1">
                                    <label for="image3" class="d-flex w-auto">
                                        <img src="images/)" + imageName + R"(" alt="Image 1">
                                        <div class="radio-form-text d-flex align-items-center w-100">
                                            <p class="w-auto">3 camera</p>
                                            <div class="price text-end">
                                                <p class="w-100 price text-end"><del>30000dh</del></p>
                                                <p class="w-100 price text-end">25000dh</p>
                                            </div>
                                        </div> 
                                    </label>
                                </div>  
                                <div class="col-11">
                                    <input type="submit" value=" Commander ! اطلب الآن " class="cart-btn w-100">
                                </div>                
                            </div>
                        </form>
                    </div>
                </div>
            </div>
        </div>
        <!-- end single product -->

        <!-- more products -->
        <div class="more-products mt-5">
            <div class="container">
                <div class="row">
                    <div class="col-lg-8 offset-lg-2 text-center">
                        <div class="section-title mb-1">	
                            <h3><span class="second-color-text">Related</span> Products</h3>
                            <p class="w-100">You May Also Like</p>
                        </div>
                    </div>
                </div>

                <div class="product-section">
                    <div class="container">
                        <div class="row justify-content-between">
                            <!-- Start Column 2 -->
                            <div class="col-12 col-md-4 col-lg-3 mb-5 me-3 mb-md-0">
                                <a class="product-item" href="Insta360 ONE X2.html">
                                    <img src="images/product-2.png" class="img-fluid product-thumbnail">
                                    <h3 class="product-title">Insta360 ONE X2</h3>
                                    <strong class="product-price">$429.99</strong>

                                    <span class="icon-cross">
                                        <img src="images/cross.svg" class="img-fluid">
                                    </span>
                                </a>
                            </div> 
                            <!-- End Column 2 -->

                            <!-- Start Column 3 -->
                            <div class="col-12 col-md-4 col-lg-3 mb-5 me-3 mb-md-0">
                                <a class="product-item" href="Fujifilm Instax Mini 11.html">
                                    <img src="images/product-3.png" class="img-fluid product-thumbnail">
                                    <h3 class="product-title">Fujifilm Instax Mini 11</h3>
                                    <strong class="product-price">$80.00</strong>

                                    <span class="icon-cross">
                                        <img src="images/cross.svg" class="img-fluid">
                                    </span>
                                </a>
                            </div> 
                            <!-- End Column 3 -->

                            <!-- Start Column 4 -->
                            <div class="col-12 col-md-4 col-lg-3 mb-5 mb-md-0">
                                <a class="product-item" href="GoPro HERO9 Black.html">
                                    <img src="images/product-4.png" class="img-fluid product-thumbnail">
                                    <h3 class="product-title">GoPro HERO9 Black</h3>
                                    <strong class="product-price">$248.95</strong>

                                    <span class="icon-cross">
                                        <img src="images/cross.svg" class="img-fluid">
                                    </span>
                                </a>
                            </div> 
                            <!-- End Column 4 -->
        
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <!-- end more products -->
    </div>

    <!-- Start Footer Section -->
    <footer class="footer-section">
        <div class="container relative">

            <div class="sofa-img">
                <img src="images/footerImage.png" alt="Image" class="img-fluid">
            </div>

            <div class="row">
                <div class="col-lg-8">
                    <div class="subscription-form">
                        <ul class="list-unstyled custom-social">
                            <li><a href="#"><span class="fa fa-brands fa-facebook-f"></span></a></li>
                            <li><a href="#"><span class="fa fa-brands fa-twitter"></span></a></li>
                            <li><a href="#"><span class="fa fa-brands fa-instagram"></span></a></li>
                            <li><a href="#"><span class="fa fa-brands fa-linkedin"></span></a></li>
                        </ul>
                    </div>
                </div>
            </div>

            <div class="border-top copyright">
                <div class="row pt-4">
                    <div class="col-lg-6">
                        <p class="mb-2 text-center text-lg-start">Copyright &copy;<script>document.write(new Date().getFullYear());</script>. All Rights Reserved. &mdash; Designed with love by <a href="https://ichhari.com/">Ichhari media</a></p>
                    </div>
                </div>
            </div>

        </div>
    </footer>
    <!-- End Footer Section -->	

    <script src="js/bootstrap.bundle.min.js"></script>
    <script src="js/tiny-slider.js"></script>
    <script src="js/custom.js"></script>
</body>
</html>

)";
    return htmlContent;
}

int main() {
    // Example data
    string imageName = "product-4.png";
    string productName = "GoPro HERO9 Black";
    string productPrice="20";
    string productDescription = "Unleash your creativity and capture stunning moments with the GoPro HERO9 Black. This versatile action camera boasts impressive 5K video and 20MP photos, allowing you to shoot breathtaking footage with incredible clarity. With advanced features like HyperSmooth 3.0 stabilization and TimeWarp 3.0, you can achieve smooth, professional-quality results in any environment. Whether you're documenting your adventures or filming your latest project, the HERO9 Black is built to deliver unmatched performance and reliability.";


    // Generate HTML content
    string htmlContent = generateHTML(imageName, productName, productPrice, productDescription);

    // Write HTML content to file
    ofstream outFile(productName + ".html");
    if (outFile.is_open()) {
        outFile << htmlContent;
        outFile.close();
        cout << "HTML file generated successfully!" << endl;
    } else {
        cerr << "Unable to create HTML file." << endl;
    }

    return 0;
}
